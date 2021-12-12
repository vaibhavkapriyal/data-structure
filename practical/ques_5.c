#include <stdio.h>

int push(char *stack,int top,int max,char c)
{
	if(stack[top]==max-1)
		printf("Stack is Full\n");
	else
	{
		top=top+1;
		stack[top]=c;
	}
	return top;
}

int pop(char *stack,int top)
{
	if(top==-1)
		printf("Stack is empty\n");
	else
	{
		printf(" %c ",stack[top]);
		top=top-1;
	}
	return top;
}

int main()
{
	int top=-1,i=0,c,max=20;
	char input[max],stack[max];
	printf("Enter a infix expression\n");
	scanf("%s",input);
	while(input[i]!='\0')
	{
		if(input[i]=='+'||input[i]=='-')
		{
			if(top==-1||stack[top]=='(')
			{
				top=push(stack,top,max,input[i]);
			}
			else if(stack[top]=='+'||stack[top]=='-'||stack[top]=='*'||stack[top]=='/'||stack[top]=='^')
			{
				top=pop(stack,top);
				i-=1;;
			}
		}
		else if(input[i]=='*'||input[i]=='/')
		{
			if(top==-1||stack[top]=='('||stack[top]=='+'||stack[top]=='-')
			{
				top=push(stack,top,max,input[i]);
			}
			else if(stack[top]=='*'||stack[top]=='/'||stack[top]=='^')
			{
				top=pop(stack,top);
				i-=1;
			}
		}
		else if(input[i]=='^')
		{
			top=push(stack,max,top,input[i]);
		}
		else if(input[i]=='(')
		{
			top=push(stack,max,top,input[i]);
		}
		else if(input[i]==')')
		{
			while(top!=-1 && stack[top]!='(')
				top=pop(stack,top);
			if(top==-1 || stack[top]!='(')
				printf("Error.......( missing\n");
			else
				top=pop(stack,top);
		}
		else
			printf(" %c ",input[i]);
		i++;
	}
	while(top!=-1)
		top=pop(stack,top);
	printf("\n");
	return 0;
}