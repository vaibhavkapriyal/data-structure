#include <stdio.h>
#include <stdlib.h>

void check(int *a,int n)
{
	int i,t=0,c=0;
	for(i=0;i<n;i++)
	{
		t=0;
		for(int j=0;j<n;j++)
		{
			if(a[i]==a[j])
			{
				t++;
			}	
		}
		if(t==1)
		{
			c++;
		}
		if(c==2)
		{
			printf("Second non repeating elements = %d\n",a[i]);
			break;
		}
	}
}

int main()
{
	int n,i;
	printf("Enter the length of the array\n");
	scanf("%d",&n);
	int a[n];
	printf("Enter the elements of the array\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	check(a,n);
	return 0;
}