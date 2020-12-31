


#include <stdio.h>

int Add(int* left, int* right)
{
    return *left+*right;
}

void Swap(int* left, int* right)
{
	int tmp = *left;
	*left = *right;
	*right = tmp;
}

int main()
{
	int a=10;
	int b=20;
	printf("a+b=%d\n",Add(&a,&b));
	
	Swap(&a,&b);
	printf("a=%d,b=%d\n",a,b);
	return 0;
}
