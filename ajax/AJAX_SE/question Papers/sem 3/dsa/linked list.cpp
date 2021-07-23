// linked list
#include<stdio.h>
#include<stdlib.h>
 struct node
 {
 	int data;
 	struct node *addr;
 };
 struct node *start=NULL;
 void ins(int);
 void disp();
 void search(int);
 void del(int);
 void copy();
 int main()
 {
 	ins(10);
 	ins(20);
 	ins(30);
 	del(10);
 	search(20);
 }
// insert function
void ins(int val)
{
	struct node *temp,*curr,*prev;
	temp=(struct node *)malloc(sizeof(struct node));
	temp->data=val;
	temp->addr=NULL;
		if(start==NULL)// first node
		{
			start=temp;
		}
		else// not first node
		{
			curr=start;
			prev=NULL;
			while(curr!=NULL&&curr->data<val)
			{
				prev=curr;
				curr=curr->addr;
			}
			temp->addr=curr;
			if(prev!=NULL)
			{
				prev->addr=temp;
			}
			else
				start=temp;
		}
		disp();
}
// display function
void disp()
{
	struct node *i;
	i=start;
	printf("\nLinked list is:");
	while(i!=NULL)
	{
		printf("%d  ",i->data);
		i=i->addr;
	}
	printf("\n");
}

void search(int s)
{
	struct node *i;
	i=start;
	while(i!=NULL)
	{
		if(s==i->data)
		{
		printf("Number Found");
		return;
	    }
		
	}
	printf("Not Found:");

}
// delete function
void del(int x)
{
	struct node *curr, *prev;
	curr = start;                               
	prev = start;
	while(curr->data!=x && curr!=NULL)
	{
		prev = curr;
		curr = curr->addr;
	}
	if(curr == NULL)
		printf("Error : %d not found\n",x);
	else if(curr == start)
		start = curr->addr;
	else
		prev->addr = curr->addr;
	disp();
}
void copy()
{
	main();
}

