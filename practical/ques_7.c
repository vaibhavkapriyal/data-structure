#include <stdio.h>
#include <stdlib.h>


typedef struct node
{
	int info;
	struct node *next;
}node;

void push(node **top,int value)
{
	node *temp;
	temp=(node*)malloc(sizeof(node));
	temp->info=value;
	temp->next=NULL;
	if(*top==NULL)
		*top=temp;
	else
	{
		temp->next=*top;
		*top=temp;
	}
}

void display(node **top)
{
	node *temp=*top;
	while(temp!=NULL)
	{
		printf(" %d ",temp->info);
		temp=temp->next;
	}
}

void pop(node **top)
{
	node *temp=*top;
	*top=temp->next;
	temp->next=NULL;
	printf("Poped value=%d\n",temp->info);
	free(temp);
}

int main()
{
    node *top=NULL;
	int c=0,value;
	printf("1. Push\n");
      printf("2. Pop\n");
      printf("3. Display\n");
      printf("4. Exit\n");
	while(c!=4)
	{
        printf("Enter your choice\n");
		scanf("%d",&c);
		switch(c)
		{
			case 1:
			{
				printf("Enter a value to be inserted\n");
				scanf("%d",&value);
				push(&top,value);
				printf("\n");
				break;
			}
			case 2:
			{
				pop(&top);
				printf("\n");
				break;
			}
			case 3:
			{
				display(&top);
				printf("\n");
				break;
			}
		}
	}
	return 0;
}