#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *addr;
};

struct node *start, *copystart;

void ins(int);
void count();
void copy();
void disp(struct node *);

int main()
{
	ins(10);//10
	ins(20);//10 20
	ins(15);//10 15 20
	ins(5);//5 10 15 20
	count();//count: 4
	copy();
	printf("after copying OG LL in copy LL then insert(30) in OG LL\n\n");
	ins(30);//5 10 15 20 30
	printf("ORIGINAL ");
	disp(start);//5 10 15 20 30
	printf("COPIED ");
	disp(copystart);//5 10 15 20
}

void ins(int val)
{
	struct node *curr, *prev, *temp;
	curr=start;
	prev=NULL;
	temp=(struct node *)malloc(sizeof(struct node));
	temp->data=val;
	temp->addr=NULL;
	if(start==NULL)
		start=temp;
	else
	{
		while(curr!=NULL && curr->data<=val)
		{
			prev=curr;
			curr=curr->addr;
		}
		temp->addr=curr;
		if(prev!=NULL)
			prev->addr=temp;
		else
			start=temp;
	}
	disp(start);
}

void count()
{
	int i=0;
	struct node *temp=start;
	while(temp!=NULL)
	{
		i++;
		temp=temp->addr;
	}
	printf("Count : %d\n\n", i);
}

void copy()
{
	struct node *i=start, *prev=NULL, *temp;
	while(i!=NULL)
	{
		temp=(struct node *)malloc(sizeof(struct node));
		temp->data=i->data;
		temp->addr=NULL;
		if(prev==NULL)
			copystart=temp;
		else
			prev->addr=temp;
		prev=temp;
		i=i->addr;
	}
}

void disp(struct node *i)
{
	printf("Linked List: ");
	while(i!=NULL)
	{
		printf(" %d ", i->data);
		i=i->addr;
	}
	printf("\n\n");
}
