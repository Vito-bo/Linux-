
#include <stdio.h>
#include <unistd.h>

int main()
{
  int count=0;
  while(1)
  {
    FILE* fp=fopen("tmp.file", "w+");
    if(!fp)
    {
      break;
    }
  }
  printf("Sum open file counts if %d\n", count);
  
  while(1)
  {
    sleep(1);
  }

  return 0;
}
