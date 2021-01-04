

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

// 三种方式获取环境变量
// 1.main函数的参数获取环境变量
int main(int argc, char* argv[], char* env[])
{
  // argc:命令行参数个数
  // argv:命令行参数具体的内容
  // env:环境变量
 
  int i=0;
  for(;i<argc;i++)
  {
    printf("%s\n",argv[i]);
  }
  
  // char* env[]
  // env[0]=xxx
  // env[1]=yyy
  // env[2]=zzz
  // env[3]=NULL
  for(i=0;env[i];i++)
  {
    printf("%s\n",env[i]);
  }
  return 0;
}


#if 0
// 2.libc库当中提供的变量来获取
int main()
{
  // libc
  extern char** environ;
  int i=0;
  for(; environ[i]; i++)
  {

    printf("%s\n",environ[i]);
  }
  return 0;
}
#endif

#if 0
// 3.通过getenv函数来获取具体变量的值
int main()
{
  // libc库当中提供的 函数来获取某一个具体的环境变量的值
  // char* getenv(const char* name);
  // name:环境变量的名称
  // char*:返回值：具体环境变量所对应的值
  char* PATH = getenv("PATH");
  printf("PATH=%s\n",PATH);

  return 0;
}
#endif

