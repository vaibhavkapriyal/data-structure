#include <stdio.h>

void toh(int n,char a,char b,char c)
{
	if(n==1)
	{
		printf("Move %c to %c\n",a,b);
		return;
	}
	toh(n-1,a,c,b);
	printf("Move %c to %c\n",a,b);
	toh(n-1,c,b,a);
	return;
}

int main()
{
	int n;
	printf("Enter the no. of inputs:\n");
	scanf("%d",&n);
	char a='A',b='B',c='C';
	toh(n,a,b,c);
	return 0;
}
