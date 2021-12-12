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
	{
          *head=temp;
	    temp->next=*head;
	}
	else
	{
		node* last = *head;
        while (last->next != *head)
            last = last->next;
        last->next = temp;
        temp->next=*head;
	}
}

void display(node **head)
{
    node* temp = *head;
    if (*head != NULL) {
        do {
            printf("%d ", temp->info);
            temp = temp->next;
        } while (temp != *head);
    }
}

int main()
{
	printf("1. Insert a node\n");
      printf("2. Display\n");
      printf("3. Exit\n");
	node *head=NULL;
	int c=0,value;
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
				insert(&head,value);
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
	return 0;
}