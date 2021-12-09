#include <stdio.h>
#include <stdlib.h>

 int main()
 {
	int n,i,t=0,c=0;
	printf("Enter the length of the array\n");
	scanf("%d",&n);
	int a[n];
	printf("Enter the elements of the array\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(a[i]==a[j])
				t++;	
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
	return 0;
}
 
