#include<conio.h>
#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *addr;
};

struct node *front=NULL;
struct node *rear=NULL;

int empty();
void display();
void insert(int);
void del();

int main()
{

	insert(10);
	insert(20);
	insert(30);
	del();
	getch();
}

int empty()
{
	if(rear==NULL)
		return 1;
	else
		return 0;
}

void display()
{
	struct node *temp;
	temp=front;
	if(!empty())
	{
		printf("Queue:");
		do
		{
			printf("%d ",temp->data);
			temp = temp->addr;
		}while(temp!=NULL);
		printf("\n");
	}
	else
		printf("Queue empty\n");
}

void insert(int x)
{
	struct node *temp;
	temp = (struct node *) malloc(sizeof(struct node));
	temp->data=x;
	temp->addr=NULL;

	if(empty())
	{
		front=temp;
		rear=temp;
	}
	else
	{
		rear->addr=temp;
		rear=temp;
	}
	display();
}

void del()
{
	if(empty())
	{
		printf("Error Queue empty\n");
	}
	else
	{
		printf("%d is deleted\n",front->data);
		front = front->addr;
		if(front==NULL)
			rear=NULL;
		display();
	}
}


