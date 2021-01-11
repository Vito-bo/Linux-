

/*------------模拟实现minishell------------*/

#include <stdio.h>
#include <unistd.h>
#include <string.h>
// 保存是字符的ASCII码值
#include <ctype.h>
#include <sys/wait.h>
#include <stdlib.h>

char g_command[1024];
int i=0;

// 获取命令
int GetCommand()
{
  // 字符数组清空
  memset(g_command, '\0', sizeof(g_command));

  printf("[test@localhost minishell]$ ");
  fflush(stdout);

  // -1是为了预留\0的位置，防止内存访问越界
  if(fgets(g_command, sizeof(g_command)-1, stdin)== NULL)
  {
    printf("fgets error\n");
    return -1;
  }
  return 0;
}

// 操作命令行
int ExecCommand(char* argv[])
{
  if(argv[0]==NULL)
  {
    printf("ExecCommand Pram error\n");
    return -1;
  }

  pid_t pid=fork();
  if(pid<0)
  {
    printf("create subprocess failed\n");
    return -1;
  }
  else if(pid==0)
  {
    //child 
    execvp(argv[0], argv);
    // 需要注意万一替换失败了，一定要杀掉
    exit(0);
  }
  else
  {
    // father
    waitpid(pid, NULL, 0);
  }
  return 0;
}

// 处理命令
int DealCommand(char* command)
{
  // 差错控制
  if(!command || *command=='\0')
  {
    printf("command error\n");
    return -1;
  }

  // 拆分命令
  int argc=0;
  char* argv[1024]={0};

  while(*command)
  {
    while(!isspace(*command) && *command!='\0')
    {
      argv[argc]=command;
      argc++;
      while(!isspace(*command) && *command!='\0')
      {
        command++;
      }
      *command='\0';
    }
    command++;
  }

  argv[argc]=NULL;

  //for(i=0;i<argc;i++)
  //{
  //  printf("argv[%d]=%s\n", i, argv[i]);
  //}
  
  // 创建子进程，子进程程序替换
  ExecCommand(argv);
  return 0;
}

int main()
{
  while(1)
  {
    // 从标准输入当中读取命令
    if(GetCommand()==-1)
    {
      continue;
    }
    // 拆分字符串，创建子进程，进程程序替换
    DealCommand(g_command);
  }

  return 0;
}












