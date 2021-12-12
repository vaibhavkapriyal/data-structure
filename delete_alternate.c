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

void display(node *head)
{
	node *temp=head;
	while(temp!=NULL)
	{
		printf(" %d ",temp->info);
		temp=temp->next;
	}
}

void deletenode(node *head)
{
    if (head == NULL)
        return;
    node *prev = head;
    node *node = head->next;

    while (prev != NULL && node != NULL)
    {
        prev->next = node->next;

        prev = prev->next;
        if (prev != NULL)
            node = prev->next;
    }
}
int main()
{
    node *head=NULL;
	int c=0,value;
	while(c!=4)
	{
	    printf("1. Insert a node\n");
        printf("2. Delete alternate node\n");
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
				insert(&head,value);
				printf("\n");
				break;
			}
			case 2:
			{
				deletenode(head);
				printf("\n");
				break;
			}
			case 3:
			{
				display(head);
				printf("\n");
				break;
			}
		}
	}
	return 0;
}
