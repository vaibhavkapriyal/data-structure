#include <stdio.h>
#include <stdlib.h>


typedef struct node
{
	int info;
	struct node *next;
}node;

void push(node **front,int value)
{
	node *temp;
	temp=(node*)malloc(sizeof(node));
	temp->info=value;
	temp->next=NULL;
	if(*front==NULL)
		*front=temp;
	else
	{
		node *last=*front;
		while(last->next!=NULL)
			last=last->next;
		last->next=temp;
		last=temp;
	}
}

void display(node **front)
{
	node *temp=*front;
	while(temp!=NULL)
	{
		printf(" %d ",temp->info);
		temp=temp->next;
	}
}

void pop(node **rear)
{
	node *temp=*rear;
	*rear=temp->next;
	temp->next=NULL;
	printf("Poped value=%d\n",temp->info);
	free(temp);
}

int main()
{
    node *head=NULL;
	int c=0,value;
	while(c!=4)
	{
	  printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice\n");
		scanf("%d",&c);
		switch(c)
		{
			case 1:
			{
				printf("Enter a value to be inserted\n");
				scanf("%d",&value);
				push(&head,value);
				printf("\n");
				break;
			}
			case 2:
			{
				pop(&head);
				printf("\n");
				break;
			}
			case 3:
			{
				display(&head);
				printf("\n");
				break;
			}
		}
	}
	return 0;
}
