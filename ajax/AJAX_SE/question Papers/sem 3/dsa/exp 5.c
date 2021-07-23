#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
struct node{
	int data;
	struct node *addr;
};
struct node *front,*rear;
int empty();
void ins(int);
void fdel();
void rdel();
void disp();

int main()
{
	ins(10);
	ins(20);
	rdel();
	fdel();
}

int empty()
{
	if(rear==NULL)
		return 1;
	else
		return 0;
}// end of empty

void ins(int val)
{
	struct node *temp;
	temp=(struct node*)malloc(sizeof(struct node));
	temp->data=val;
	temp->addr=NULL;
		if(empty())
		{
			front=temp;
		}
		else
		{
			rear->addr=temp;
		}
		rear=temp;
	disp();
}

void disp()
{
	struct node *i=front;
	printf("dequeue: ");
	if(!empty())
	{
		while(i!=NULL)
		{
			printf("%d ",i->data);
			i=i->addr;
		}
		printf("\n");
	}
}

void fdel()
{
	if(!empty())
	front=front->addr;
	if(front==NULL)
	rear=NULL;
	disp();
}

void rdel()
{
	struct node *i=front;
	if(!empty())
	{
		while(i->addr!=rear)
		{ 
			i=i->addr;
		}
		i->addr=NULL;
		rear=i;
		if(rear==NULL)
		front=NULL;
	}
	disp();
}
