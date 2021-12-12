#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int info;
	struct node *next;
	struct node *prev;
}node;

void insert(node**head,node **tail,int value)
{
	node *temp;
	temp=(node*)malloc(sizeof(node));
	temp->info=value;
	temp->next=NULL;
	if(*tail==NULL)
	{
		*head=temp;
		*tail=temp;
		temp->prev=NULL;
	}
	else
	{
		(*tail)->next=temp;
		temp->prev=*tail;
		*tail=temp;
	}
}



void display(node **head)
{
	node *temp=*head;
	while(temp!=NULL)
	{
		printf(" %d ",temp->info);
		temp=temp->next;
	}
	printf("\n");
}

void checkpalin(node **head,node **tail)
{
	node *temp1=*head;
	node *temp2=*tail;
	while(temp1->next!=NULL&&temp2->prev!=NULL)
	{
		if(temp1->info!=temp2->info)
		{
			printf("\nList is not palindrome\n");
			return;
		}
		temp2=temp2->prev;
		temp1=temp1->next;
	}
	printf("\nList is palindrome\n");
}

int main()
{
	node *head=NULL;
	node *tail=NULL;
	int c=0,value;
	printf("1. Insert a node\n");
      printf("2. Display\n");
      printf("3. Exit\n");
	while(c!=3)
	{
        printf("Enter your choice\n");
		scanf("%d",&c);
		switch(c)
		{
			case 1:
			{
				printf("Enter a value to be inserted\n");
				scanf("%d",&value);
				insert(&head,&tail,value);
				printf("\n");
				break;
			}
			case 2:
			{
				display(&head);
				printf("\n");
				break;
			}
		}
	}
	checkpalin(&head,&tail);
	return 0;
}