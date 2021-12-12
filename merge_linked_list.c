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
	temp->info=value;
	temp->next=NULL;
	if(*head==NULL)
		*head=temp;
	else
	{
		node *last=*head;
		while(last->next!=NULL)
			last=last->next;
		last->next=temp;
		last=temp;
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

void sort(node **head)
{
	int t;
	node *temp1=*head;
	while(temp1!=NULL)
	{
		node *temp2=*head;
		while(temp2!=NULL)
		{
			if(temp1->info>temp2->info)
			{
				t=temp1->info;
				temp1->info=temp2->info;
				temp2->info=t;
			}
			temp2=temp2->next;
		}
		temp1=temp1->next;
	}
}
void merge(node **head1,node **head2)
{
	node *last=*head1;
	while(last->next!=NULL)
		last=last->next;
	last->next=*head2;
}
int main()
{
      node *head1=NULL;
      node *head2=NULL;
	int c=0,value;
	printf("1. Insert in list 1\n");
      printf("2. Insert in list 2\n");
      printf("3. Display list 1\n");
      printf("4. Display list 2\n");
      printf("5. Exit\n");
	while(c!=5)
	{
        printf("Enter your choice\n");
		scanf("%d",&c);
		switch(c)
		{
			case 1:
			{
				printf("Enter a value to be inserted\n");
				scanf("%d",&value);
				insert(&head1,value);
				printf("\n");
				break;
			}
			case 2:
			{
				printf("Enter a value to be inserted\n");
				scanf("%d",&value);
				insert(&head2,value);
				printf("\n");
				break;
			}
			case 3:
			{
				display(&head1);
				printf("\n");
				break;
			}
			case 4:
			{
				display(&head2);
				printf("\n");
				break;
			}
		}
	}
	sort(&head1);
	sort(&head2);
	display(&head1);
	display(&head2);
	merge(&head1,&head2);
	display(&head1);
	
	return 0;
}
