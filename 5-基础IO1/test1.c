
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main()
{
  //close(0);

  int fd=open("./tmp_file", O_RDWR, 0664);
  printf("fd=%d\n", fd);
  while(1)
  {
    sleep(1);
  }

  return 0;
}
