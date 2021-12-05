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
	{
        head=temp;
	    temp->next=head;
	}
	else
	{
		node* last = head;
        while (last->next != head)
            last = last->next;
        last->next = temp;
        temp->next=head;
	}
}
void display()
{
    node* temp = head;
    if (head != NULL) {
        do {
            printf("%d ", temp->info);
            temp = temp->next;
        } while (temp != head);
    }
}

void deletenode( int key)
{
    if (head == NULL)
        return;
    node *curr = head, *prev;
    while (curr->info != key)
    {
        if (curr->next == head)
        {
            printf("\nGiven node is not found"
                   " in the list!!!");
            break;
        }

        prev = curr;
        curr = curr->next;
    }

    // Check if node is only node
    if (curr->next == head)
    {
        head = NULL;
        free(curr);
        return;
    }
    // it is first node
    if (curr == head)
    {
        prev = head;
        while (prev->next != head)
            prev = prev->next;
        head = curr->next;
        prev->next = head;
        free(curr);
    }
    // check if node is last node
    else if (curr->next == head)
    {
        prev->next = head;
        free(curr);
    }
    else
    {
        prev->next = curr->next;
        free(curr);
    }
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
