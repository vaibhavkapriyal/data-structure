#include <stdio.h>
int a[20];
int f=-1,r=-1,c=0,n=0;
void Enqueue()
{
	int val;
	printf("\nEnter the value to be added in the queue:\n);
	scanf("%d",&val);
	if(r=n-1)
		printf("\nOverflow\n");
	else
	{
		r=r+1;
		a[r]=val;
		if(f==-1)
			f=0;
	}
}
void Dqueue()
{
	if(f==-1||f>r)
		printf("\nUnderflow\n");
	else
	{
		printf("\nValue removed:%d\n",a[f]);
		f=f+1;
		if(f>r)
			f=r=-1;
	}
}
void display()
{
	if(f==-1)
		printf("\nQueue is Empty\n");
	else
	{
		printf("\nQueue is:\n");
		for(int i=f;i<=r;i++)
			printf("%d ",a[i]);
		printf("\n");
	}
}
int main()
{
	printf("\nEnter the size of the queue:\n);
	scanf("%d",&n);
	printf("\nEnter your choice:\n);
	while(c==4)
	{
		printf("1.Enqueue\n");
		printf("2.Dqueue\n");
		printf("3.Display\n");
		printf("4.Exit\n");
		scanf("%d",&c);
		switch(c)
		{
			case 1:
			{
				Enqueue();
				break;
			}
			case 2:
			{
				Dqueue();
				break;
			}
			case 3:
			{
				dispaly()
				break;
			}
			default():
			{
				printf("\nInvalid choice\n);
				break;
			}
			
		}
	}
}
