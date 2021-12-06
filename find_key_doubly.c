#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int info;
	struct node *next;
	struct node *prev;
}node;

node *head=NULL;
node *tail=NULL;

void insert(int value)
{
	node *temp;
	temp=(node*)malloc(sizeof(node));
	temp->info=value;
	temp->next=NULL;
	if(tail==NULL)
	{
		head=temp;
		tail=temp;
		temp->prev=NULL;
	}
	else
	{
		tail->next=temp;
		temp->prev=tail;
		tail=temp;
	}
}

void deletenode(int key)
{
	node *temp=head;
	while(temp->info!=key)
	{
		if(temp->next==NULL)
		{
			printf("\nKey not found\n");
			break;
		}
		temp=temp->next;
	}
	if(temp==head)
	{
		head=temp->next;
		head->prev=NULL;
		temp->next=NULL;
	}
	else if(temp==tail)
	{
		tail=temp->prev;
		tail->next=NULL;
		temp->prev=NULL;
	}
	else
	{
		(temp->prev)->next=temp->next;
		(temp->next)->prev=temp->prev;
		temp->next=NULL;
		temp->prev=NULL;
	}
	free(temp);
}

void display()
{
	node *temp=head;
	while(temp!=NULL)
	{
		printf(" %d ",temp->info);
		temp=temp->next;
	}
	printf("\n");
}
int main()
{
	int c=0,n,value;
	while(c!=4)
	{
	    printf("1. Insert a node\n");
        printf("2. Find and Delete a key\n");
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
				insert(value);
				printf("\n");
				break;
			}
			case 2:
			{
				printf("Enter the key to be searched\n");
				scanf("%d",&n);
				deletenode(n);
				printf("\n");
				break;
			}
			case 3:
			{
				display();
				printf("\n");
				break;
			}
		}
	}
	return 0;
}
