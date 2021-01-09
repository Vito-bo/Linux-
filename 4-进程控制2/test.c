
// 进程程序替换
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
  int i=0;
  extern char** environ;
  printf("我是test可执行程序\n");
  for(i=0; environ[i]; i++)
  {
    printf("%s\n",environ[i]);
    printf("\n");
  }
  printf("我是test可执行程序，打印完毕环境变量了\n");

  for(i=0;i<argc;i++)
  {
    printf("pram[%d] : %s\n",i,argv[i]);
  }
  printf("我是test可执行程序，打印完毕命令行参数了\n");
  sleep(5);

  /*-----------exec l系列函数-----------------*/
  //execl("./myexec", "exec", "-l", NULL);
  // execlp("/home/wudu/work/linux/linux-68/linux-lesson11/myexec", "myexec", "-l", NULL);
  // char* envp[] = {"MYENV=xxxx", "HEHE=yyyy", NULL};
  //
  // execle("/home/wudu/work/linux/linux-68/linux-lesson11/myexec", "myexec", "-l", NULL, envp);
  //
  /*-----------exec v系列函数-----------------*/
  // char* const argv1[] = {"myexec", "-l","-hello", "-123456789", NULL};
  //                      
  // execv("/home/wudu/work/linux/linux-68/linux-lesson11/myexec", argv1); 
  // execv("myexec", argv1); 
  // execve("myexec", argv1, environ); 
  // perror("execl");
  
  perror("execl");
  printf("bobooboboboobob\n");
  exit(-1);
  return 0;
}
