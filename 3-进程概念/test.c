
#include <stdio.h>
#include <unistd.h>

int main()
{
  printf("~~~~~~~~~~~~~~~~~~~~~\n");
  //创建子进程，系统调用函数 fork
  pid_t pid=fork();

  if(pid<0)
  {
    //没有内存的时候，可能会导致此结果，因为创建进程是需要耗费内存的
    perror("fork");
    return 0;
  }
  else if(pid==0)
  {
    //child
    printf("i am child:[%d]-[%d]\n",getpid(),getppid());
  }
  else
  {
    // father
    while(1)
    {
       sleep(1);
    }

    printf("i am father:[%d]-[%d]\n",getpid(),getppid());
  }
  //获取当前进程的pid，使用getpid()
  //获取当前进程的父进程的pid，使用getppid()
  
  printf("$$$$$$$$$$$$$$$$$$$$$$\n");
  return 0;
}

