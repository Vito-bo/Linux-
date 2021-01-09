
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>


int main(int argc, char* argv[], char* env[])
{
  int i=0;
  printf("我是myexec可执行程序，我要开始执行了\n");
  for(i=0;env[i];i++)
  {
    printf("%s\n",env[i]);
    printf("\n");
  }
  printf("我是myexec可执行程序，我已经打印完毕环境变量了\n");

  for(i=0; i<argc; i++)
  {
    printf("parm[%d]: %s\n",i, argv[i]);
  }
  printf("我是myexec可执行程序，我已经打印完毕命令行参数了\n");

  while(1)
  {
    printf("baishui\n");
    sleep(1);
  }
  return 0;
}
