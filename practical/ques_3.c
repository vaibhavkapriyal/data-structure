#include <stdio.h>
#include <stdlib.h>

void reverse(int *ptr,int i,int j)
{
	int temp;
	if(i>=j)
	{
		return;
	}
	temp=ptr[i];
	ptr[i]=ptr[j];
	ptr[j]=temp;
	reverse(ptr,i+1,j-1);	
}

int main()
{
	int *ptr=NULL;
	int i,len=0;
	printf("ENTER THE SIZE OF ARRAY:");
	scanf("%d",&len);
	ptr=(int*)malloc(len*sizeof(int));
	if(ptr==NULL)
	{
		printf("\nMemory not allocated\n");
		exit(1);
	}
	else
	{
		printf("ENTER THE ELEMENTS:");

		for(i=0;i<len;++i)
		{
			scanf("%d", &ptr[i]);
		}
		printf("Array elements are \n");
		for(i=0;i<len;++i)
		{		
			printf("%d ", ptr[i]);
		}
		reverse(ptr,0,len-1);
		printf("\nArray elements in reverse are \n");
		for(i=0;i<len;++i)
		{		
			printf("%d ", ptr[i]);
		}
		free(ptr);
		
	}
	return 0;
}
