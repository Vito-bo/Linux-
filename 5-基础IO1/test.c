
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main()
{

  FILE* fp = fopen("tmp.file","w+");
  if(!fp)
  {
    perror("fopen");
    return 0;
  }
  
  int ret=fseek(fp, -1, SEEK_SET);
  printf("fseek ret=%d\n", ret);
  perror("fseek");


  const char* data="vitobo88";
  ssize_t writesize = fwrite(data, 1, strlen(data), fp);
  //ssize_t writesize = fwrite(data, 3 ,4, fp);

  // 含义是写入了多少个块,如果size是1，则可以认为是写入了多少个字节
  printf("writesize: %lu\n", writesize);
 
  fseek(fp, -4, SEEK_END);

  // 使用
  char buf[1024];
  memset(buf,'\0', sizeof(buf));
  //ssize_t readsize = fread(buf, 2, 3, fp); 
  //printf("readsize:%lu\n", readsize);
  //printf("readbuf:%s\n", buf);
  
  ssize_t readsize = fread(buf, 1, 8, fp); 
  printf("readsize: %lu\n", readsize);
  printf("readbuf: %s\n", buf);
 
  fclose(fp);
  return 0;
}
