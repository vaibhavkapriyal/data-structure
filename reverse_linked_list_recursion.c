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
	insert(&head,20);
	insert(&head,30);
	insert(&head,40);
	insert(&head,50);
	insert(&head,60);
	insert(&head,70);
	display(head);
	reverse(head);
	return 0;	
}
