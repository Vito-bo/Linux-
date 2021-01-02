


#include <stdio.h>
#include <stdlib.h>

// 模拟实现strlen
// 1.计数器方式
int my_strlen1(const char* str)
{
  int count=0;
  while(*str)
  {
    count++;
    str++;
  }
  return count;
}

// 2.不能创建临时变量计数
int my_strlen2(const char* str)
{
  if(*str == '\0')
    return 0;
  else
    return 1+my_strlen2(str+1);
}

// 3.指针-指针
int my_strlen3(char* s)
{
  char* p=s;
  while(*p != '\0')
  {
    p++;
  }
  return p-s;
}

int main()
{
  const char* ch="hello world";

  int len = 0;
  len = my_strlen1(ch);

  printf("%s\n",ch);
  printf("%d\n",len);
  return 0;
}
