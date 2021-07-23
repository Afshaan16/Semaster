#include<stdio.h>
#define SIZE 5

int stack[SIZE];
int st=0;

int stack_empty();
int stack_full();
void push(int);
void pop();
void stack_top();
void display();

int main()
{
	int choice,val;
	do
	{
		printf("\n1. Push\n2. Pop\n3. Top\n4. Display\n5. Exit");
		printf("\nEnter your choice - ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				printf("Enter the value to push - ");
				scanf("%d",&val);
				push(val);
				break;
			case 2:
				pop();
				break;
			case 3:
				stack_top();
				break;
			case 4:
				display();
				break;
			case 5:
				break;
			default:
				printf("Error! Invalid Input");
				break;
		}
	}
		while(choice!=5);                                                                                	
}

int stack_empty()
{
	if(st==0)
	return 1;
	else
	return 0;
}

int stack_full()
{
	if(st==SIZE)
	return 1;
	else
	return 0;
}

void push(int val)
{
	if(stack_full())
	printf("Error! Stack full\n");
	else
	{
		stack[st]=val;
		st++;
		display();
	}
}

void pop()
{
	if(stack_empty())
	printf("Error! Stack empty\n");
	else
	{
		printf("%d is the popped element\n",stack[st-1]);
		st--;
		display();
	}
}

void stack_top()
{
	if(stack_empty())
	printf("Error! Stack empty\n");
	else
	{
		printf("Top of stack is : %d\n",stack[st-1]);
	}
}

void display()
{
	int i;
	printf("Stack : ");
	for(i=0;i<st;i++)
	{
		printf("%d ",stack[i]);
	}
	printf("\n");
}
