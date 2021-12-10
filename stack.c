#include <stdio.h>
#include <stdlib.h>

int push(int *stack,int top,int n)
{
	int value;
	printf("Enter a value:\n");
	scanf("%d",&value);
	if(top==n)
		printf("Stack is full\n");
	else
	{
		top=top+1;
		stack[top]=value;
		return top;
	}
}
int pop(int *stack,int top)
{
	if(top==-1)
		printf("Stack is empty\n");
	else
	{
		printf("Poped value is %d\n",stack[top]);
		top=top-1;
		return top;
	}
}
void display(int *stack,int top)
{
	if(top==-1)
		return;
	printf("%d ",stack[top]);
	display(stack,top-1);
}

int main()
{
	int n=20,top=-1;
	int stack[20];
	int c=0;
	while(c!=4)
	{
	    printf("1. Insert in Stack\n");
        printf("2. Delete from Stack\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice\n");
		scanf("%d",&c);
		switch(c)
		{
			case 1:
			{
				top=push(stack,top,n);
				break;
			}
			case 2:
			{
				top=pop(stack,top);
				break;
			}
			case 3:
			{
				display(stack,top);
				printf("\n");
				break;
			}
		}
	}
}
