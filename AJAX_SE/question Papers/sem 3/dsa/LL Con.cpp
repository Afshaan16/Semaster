//linked list with insert, delete, display/traverse, concat
#include <stdio.h>
#include <stdlib.h>

struct node{//node of linked list
	int val;//value part
	struct node *addr;//address of next node
};
struct node *start1;//holds address of first node, initially NULL, for LL1
struct node *start2;//holds address of first node, initially NULL, for LL2
struct node *copyStart;//holds the address of first node of copied linked list

void traverse(struct node *s)//travel from first node to last node in LL1 or LL2, s=start1 or start2 resp.
{
	struct node *cur = s;
	
	while(cur!=NULL)
	{
		printf("%d ",cur->val);
		cur = cur->addr;
	}
	printf("\n");
}

struct node * ins(int x, struct node *s)//insert a new element in LL1 or LL2, s=start1 or start2 resp., return update start value
{
	struct node *temp, *cur, *prev;
    cur = s;
    prev = NULL;

	temp = (struct node *)malloc(sizeof(struct node));//create a new node
	temp->val = x;//assign value
	temp->addr = NULL;//make address part as NULL

	if(s==NULL)//if first node
	{
		s=temp;
	}
	else//find place for it in sorted linked list
	{
		while(cur!=NULL && cur->val <= x)
        {
              prev = cur;
              cur = cur->addr;
        }
		temp->addr = cur;
		if(prev!=NULL) prev->addr = temp;
		else s=temp;
	}
	traverse(s);//display respective LL 
	return s;//return update respective start value
}

struct node * del(int x, struct node *s)//delete a node if present in LL1 or LL2, s=start1 or start2 resp., return update start value
{
	struct node *cur, *prev;
	cur = s;
	prev = NULL;

	if(s==NULL)//no element in linked list
	{
		printf("Error : list is empty");
	}
	else//atleast 1 element
	{
		while(cur!=NULL && cur->val==x)//find a node having value=x from first node to last node
		{
			prev = cur;
			cur = cur->addr;
		}
		if(cur==NULL)//not found
			printf("Error : not found");
		else//found, delete it
		{
			if(prev==NULL)//first element
				s = cur->addr;
			else
				prev->addr = cur->addr;//non first element
			traverse(s);
		}
	}
	return s;
}

void concat(struct node *s1, struct node *s2)
{
	//go to the end of LL1
	struct node *temp=s1;
	while(temp->addr!=NULL)
	{
		temp=temp->addr;
	}//temp will be finally holding address of last node of LL1
	//concat LL2 after temp
	temp->addr=s2;
	printf("LL1 + LL2: ");
	traverse(s1);
}

void count()
{
	int i=0;//var to count nodes
	struct node *temp=start1;
	
	while(temp!=NULL)//until no more nodes to visit
	{
		i++;//increment counter for each node
		temp=temp->addr;//move to next node
	}
	printf("count: %d\n",i);
}

void copy()
{
	struct node *i=start1;//address of first node of OG LL
	struct node *temp;//for creating new node in copy LL
	struct node *prev=NULL;
	while(i!=NULL)//until no more nodes to visit
	{
		temp=(struct node *)malloc(sizeof(struct node));//allocate memory
		temp->val=i->val;//copy data
		temp->addr=NULL;//make address part as null
		if(prev==NULL)//if first node of copy LL
			copyStart=temp;
		else//not a first node of copy LL
			prev->addr=temp;//attach with previous node
		prev=temp;//make new node as previous in order to update address part with address of next node
		i=i->addr;//move to next node of OG LL
	}
}

int main()
{
	printf("LL1: ");
    start1 = ins(10, start1);//LL1:10 LL2:
    printf("LL1: ");
    start1 = ins(20, start1);//LL1:10 20 LL2:
    printf("LL1: ");
    start1 = ins(15, start1);//LL1:10 15 20 LL2:
    printf("LL1: ");
    start1 = ins(5, start1);//LL1:5 10 15 20 LL2:
    printf("LL2: ");
    start2 = ins(30, start2);//LL1:10 20 LL2:30
    printf("LL2: ");
    start2 = ins(15, start2);//LL1:10 20 LL2:15 30
    count();
    concat(start1, start2);//concat both list
    copy();
	printf("COPY LL:");
    traverse(copyStart);
}
