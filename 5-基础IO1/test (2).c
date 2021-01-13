
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main()
{
  // flags:
  // 以下三个选项当中是必选项，且三者当中只能选择一个
  // O_RDONLY:以只读方式打开
  // O_WRONLY:以只写方式打开
  // O_RDWR:以可读可写方式打开
  
  // 以下为可选项，可以选择多个
  // O_CREAT:如果不存在则创建文件
  // O_TRUNC:截断文件（清空文件）
  // O_APPEND:以追加方式打开文件
  int fd=open("./tmp_file", O_RDWR | O_CREAT, 0664);
  if(fd<0)
  {
    perror("open");
    return 0;
  }
  printf("fd=%d\n", fd);

  int writesize=write(fd, "vitobobo", 8);
  if(writesize<0)
  {
    perror("write");
    return 0;
  }
  printf("writesize = %d\n", writesize);

  lseek(fd, 0, SEEK_SET);

  char buf[1024];
  memset(buf, '\0', sizeof(buf));
  int readsize=read(fd, buf, sizeof(buf)-1);
  if(readsize<0)
  {
    perror("readsize");
    return 0;
  }
  printf("readsize=%d\n", readsize);
  printf("read buf is %s\n", buf);

  close(fd);
  while(1)
  {
    sleep(1);
  }

  return 0;
}
