

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void func()
{
  printf("太冷了\n");
}

int main()
{
  atexit(func);
  //  _exit(99);
  printf("最美不是下雨天");
  sleep(3);
  _exit(-1);
  //fflush(stdout);
  //varexit(1);
  printf("我想吃豆腐脑");
  
  return 0;
}
