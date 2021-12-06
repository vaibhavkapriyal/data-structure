#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int info;
	struct node *next;
}node;

node *head=NULL;

void insert(int value)
{
	node *temp;
	temp=(node*)malloc(sizeof(node));
	temp->info=value;
	temp->next=NULL;
	if(head==NULL)
		head=temp;
	else
	{
		node *last=head;
		while(last->next!=NULL)
			last=last->next;
		last->next=temp;
		last=temp;
	}
}

void display()
{
	node *temp=head;
	while(temp!=NULL)
	{
		printf(" %d ",temp->info);
		temp=temp->next;
	}
}

void deletenode(int key)
{
     node *prev, *cur=head;
    while ( cur->info != key)
    {
        if(cur->next==NULL)
        {
            printf("\nKey not Found\n");
            break;
        }
        prev = cur;
        cur = cur->next;
    }
    if(cur==head)
    {
        head=cur->next;
        cur->next=NULL;
    }
    else if(cur->next==NULL)
    {
        prev->next=NULL;
    }
    else
    {
        prev->next=cur->next;
        cur->next=NULL;
    }
    free(cur);
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
