#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

struct node{
	int data;
	struct node *addr;
};

struct node *top, *start;

void push(int);
void pop();
void disp();

int main()
{
	push(10);
	push(20);
	push(30);
	pop();
	getch();
}

void push(int val)
{
	struct node *temp;
	struct node *i=start;
	temp=(struct node*)malloc(sizeof(struct node));
	temp->data=val;
	temp->addr=NULL;
	if(start==NULL)
		start=temp;
	else
	{
		while(i->addr!=NULL)
		{
			i=i->addr;
		}
		i->addr=temp;
	}
	top=temp;
	disp();
}

void pop()
{
	struct node *i=start;
	if(start==NULL)
		printf("Error! Empty Queue");
	else if(start==top)
	{
		start=NULL;
		top=NULL;
	}
	else
	{
		while(i->addr!=top)
		{
			i=i->addr;
		}
		top=i;
		top->addr=NULL;
	}
	disp();
}

void disp()
{
	struct node *i=start;
	printf("Stack: ");
	while(i!=NULL)
	{
		printf(" %d ",i->data);
		i=i->addr;
	}
	printf("\n");
}
