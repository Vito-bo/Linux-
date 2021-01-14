
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main()
{
  // 0 1 2
  int fd=open("./tmpfile", O_RDWR | O_CREAT, 0664);
  if(fd<0)
  {
    perror("open");
    return 0;
  }
  else
  {
    // 将标准输出 重定向到 tmpfile当中去
    // 3：tmpfile
    // 1：标准输出
    // 需要被修改的是 标准输出
    // 模板是 tmpfile
    dup2(3,1);
    printf("welcome to xian!\n");
  }
  return 0;
}
