
#include <stdio.h>
#include <unistd.h>

int main()
{
  printf("begin....\n");
  fork();
  printf("end...pid=%d\n",getpid());
  return 0;
}
