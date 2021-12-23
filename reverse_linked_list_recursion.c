#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int info;
	struct node *next;
}node;

void insert(node **head,int value)
{
	node *temp;
	temp=(node*)malloc(sizeof(node));
	if(temp==NULL)
	{
		printf("No memory allocated\n");
		exit(1);
	}
	else
	{
		temp->info=value;
		temp->next=NULL;
		if(*head==NULL)
		{
			*head=temp;
		}
		else
		{
			temp->next=*head;
			*head=temp;
		}
	}
}

void display(node *head)
{
	node *temp=head;
	while(temp!=NULL)
	{
		printf("%d ",temp->info);
		temp=temp->next;
	}
	printf("\n");
}

node* reverse(node *head)
{
	node *temp=head;
	if(temp==NULL)
	{
		return(NULL);
	}
	reverse(temp->next);
	printf("%d ",temp->info);
}

int main()
{
	node *head=NULL;
	int c=0,n,value;
	printf("1. Insert at front\n");
	printf("2. Display\n");
	printf("3. Reverse Display\n");
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
				insert(&head,value);
				break;
			}
			case 2:
			{
				display(head);
				break;
			}
			case 3:
			{	
				reverse(head);
				printf("\n");
				break;
			}
			default:
			{
				printf("Invalid Choice\n");
				break;
			}
		}
	}
	return 0;
}
