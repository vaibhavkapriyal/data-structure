#include <stdio.h>
#include <stdlib.h>
 
typedef struct node
{
	int info;
	struct node *next;
}node;

node *head=NULL;

void insertfront(int value)
{
	node *temp;
	temp=(node*)malloc(sizeof(node));
	temp->info=value;
	temp->next=NULL;
	if(head==NULL)
		head=temp;
	else
	{
		temp->next=head;
		head=temp;
	}
}
void insertend(int value)
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
void insertmid(int value,int n)
{
	node *temp;
	temp=(node*)malloc(sizeof(node));
	temp->info=value;
	temp->next=NULL;
		if(head==NULL)
			head=temp;
		else
		{            
            node *mid=head;   
            for(int i=0;i<n;i++)  
            {  
                mid = mid->next;  
                if(temp == NULL)  
                {  
                    printf("\ncan't insert\n");  
                    return;  
                }  
              
            }  
            temp ->next = mid ->next;   
            mid ->next = temp;    
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
int main()
{
	int c=0,n,value;
	printf("1. Insert at front\n");
	printf("2. Insert at end\n");
	printf("3. Insert at random\n");
	printf("4. Display\n");
	printf("5. Exit\n");
	printf("Enter your choice\n");
	while(c!=5)
	{
		scanf("%d",&c);
		switch(c)
		{
			case 1:
			{
				printf("Enter a value to be inserted\n");
				scanf("%d",&value);
				insertfront(value);
				break;
			}
			case 2:
			{
				printf("Enter a value to be inserted\n");
				scanf("%d",&value);
				insertend(value);
				break;
			}
			case 3:
			{
				printf("Enter a value to be inserted\n");
				scanf("%d",&value);
				printf("Enter the position\n");
				scanf("%d",&n);
				insertmid(value,n);
				break;
			}
			case 4:
			{
				display();
				break;
			}
		}
	}
	return 0;
}

