
//linked list copy, count, split
#include<stdio.h>
#include<stdlib.h>

struct node//structure of node
{
	int data;//data part
	struct node *addr;//address part, holds address of next node
};
struct node *start;//holds the address of first node of orginal linked list
struct node *copyStart;//holds the address of first node of copied linked list

void ins(int);//inserts new node in linked list
void disp(struct node *);//prints linked list from specified start address
void count();//to count the nodes in LL
void copy();//to copy OG LL in copy LL

int main()
{
	ins(10);//10
	ins(20);//10 20
	ins(15);//10 15 20
	ins(5);//5 10 15 20
	count();//count: 4
	copy();
	ins(30);//5 10 15 20 30
	printf("after copying OG LL in copy LL then insert(30) in OG LL\n");
	printf("OG LL:");
	disp(start);//5 10 15 20 30
	printf("COPY LL:");
	disp(copyStart);//5 10 15 20
}

void ins(int val)
{
	struct node *temp, *cur, *prev;
    cur = start;
    prev = NULL;

	temp = (struct node *)malloc(sizeof(struct node));//create a new node
	temp->data = val;//assign value
	temp->addr = NULL;//make address part as NULL

	if(start==NULL)//if first node
	{
		start=temp;
	}
	else//find place for it in sorted linked list
	{
		while(cur!=NULL && cur->data <= val)
        {
              prev = cur;
              cur = cur->addr;
        }
		temp->addr = cur;
		if(prev!=NULL) prev->addr = temp;
		else start=temp;
	}
	disp(start);
}

void disp(struct node *i)//print linked list as per start address in i
{
	while(i!=NULL)//until no more nodes to visit
	{
		printf("%d ",i->data);//print data
		i=i->addr;//move to next node
	}
	printf("\n");//finally print line break
}

void count()
{
	int i=0;//var to count nodes
	struct node *temp=start;
	
	while(temp!=NULL)//until no more nodes to visit
	{
		i++;//increment counter for each node
		temp=temp->addr;//move to next node
	}
	printf("count: %d\n",i);
}

void copy()
{
	struct node *i=start;//address of first node of OG LL
	struct node *temp;//for creating new node in copy LL
	struct node *prev=NULL;
	while(i!=NULL)//until no more nodes to visit
	{
		temp=(struct node *)malloc(sizeof(struct node));//allocate memory
		temp->data=i->data;//copy data
		temp->addr=NULL;//make address part as null
		if(prev==NULL)//if first node of copy LL
			copyStart=temp;
		else//not a first node of copy LL
			prev->addr=temp;//attach with previous node
		prev=temp;//make new node as previous in order to update address part with address of next node
		i=i->addr;//move to next node of OG LL
	}
}

