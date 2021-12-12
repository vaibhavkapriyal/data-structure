#include <stdio.h>

void Enqueue(int *a,int *f,int *r,int n)
{
	int val;
	printf("\nEnter the value to be added in the queue:\n");
	scanf("%d",&val);
	if(*r==n-1)
		printf("\nOverflow\n");
	else
	{
		*r=*r+1;
		a[*r]=val;
		if(*f==-1)
			*f=0;
	}
}
void Dqueue(int *a,int *f,int *r)
{
	if(*f==-1||*f>*r)
		printf("\nUnderflow\n");
	else
	{
		printf("\nValue removed:%d\n",a[*f]);
		*f=*f+1;
		if(*f>*r)
			*f=*r=-1;
	}
}
void display(int *a,int *f,int *r)
{
	if(*f==-1)
		printf("\nQueue is Empty\n");
	else
	{
		printf("\nQueue is:\n");
		for(int i=*f;i<=*r;i++)
			printf("%d ",a[i]);
		printf("\n");
	}
}
int main()
{
	int a[20];
	int f=-1,r=-1,c=0,n=0;
	printf("\nEnter the size of the queue:\n");
	scanf("%d",&n);
	printf("1.Enqueue\n");
	printf("2.Dqueue\n");
	printf("3.Display\n");
	printf("4.Exit\n");
	while(c!=4)
	{
		printf("\nEnter your choice:\n");
		scanf("%d",&c);
		switch(c)
		{
			case 1:
			{
				Enqueue(a,&f,&r,n);
				break;
			}
			case 2:
			{
				Dqueue(a,&f,&r);
				break;
			}
			case 3:
			{
				display(a,&f,&r);
				break;
			}
			default:
			{
				printf("\nInvalid choice\n");
				break;
			}
			
		}
	}
}
