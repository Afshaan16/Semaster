/*
circular Queue using linked list
*/

#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *addr;	
};

struct node *head, *rear;
void ins(int val);
void del();
void disp();
int empty();

int main()
{
	ins(10);//10
	ins(20);//10 20
	ins(30);//10h(20) 20(30) 30r(10)
	del();//20h(30) 30r(20)
	del();//30hr(30)
	del();//hr=null
}

int empty()
{
	if(head==NULL)
		return 1;
	else
		return 0;
}

void ins(int val)//20
{
	struct node *temp;
	temp = (struct node *)malloc(sizeof(struct node));
	temp->data=val;
	temp->addr=NULL;//10hr(10) 20
	
	if(empty())
	{
		head=temp;
	}
	else
	{
		rear->addr=temp;//10hr(20) 20
	}
	rear=temp;//10h(20) 20r
	temp->addr=head;//10h(20) 20r(10)
	disp();
}

void disp()
{
	struct node *i=head;
	printf("CQ: ");
	if(!empty())
	{
		do
		{
			printf("%d ",i->data);
			i=i->addr;
		}while(i!=head);	
	}
	printf("\n");
}

void del()
{
	if(!empty())
	{
		if(head==rear)
		{
			head=NULL;
			rear=NULL;
		}
		else
		{
			head=head->addr;
			rear->addr=head;
		}
			
	}
	disp();
}
