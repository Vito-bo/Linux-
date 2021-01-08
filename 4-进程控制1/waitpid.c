

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>


int main()
{

  pid_t pid=fork();
  if(pid<0)
  {
    return 0;
  }
  else if(pid==0)
  {
    // child
    printf("i am child\n");
    sleep(1);
   //while(1)
   // {
   //   ;
   // }
    exit(1);
  }
  else
  {
    // 调用waitpid
    int status;
    while(waitpid(pid,&status,WNOHANG)==0);
    printf("return code:%d\n",(status>>8)& 0xff); 
    printf("siganl code:%d\n",status & 0x7f);
    while(1)

    {
      printf("我完成任务了!\n");
      sleep(1);
    }
  }   
  
  return 0;
}
