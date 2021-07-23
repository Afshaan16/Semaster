#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *addr;
};
struct node *start1;
struct node *start2;

void ins(int,struct node *);
void del(int,struct node *);
void concat(struct node *,struct node *);
void disp();


void ins(int val,struct node *s)
{
	struct node *temp,*curr,*prev;
	curr=s;
	prev=NULL;
	temp->data=val;
	temp->addr=NULL;
	if(s==NULL)
		s=temp;
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
			s=temp;
	}
	disp();
}
void disp(struct node *s)//travel from first node to last node in LL1 or LL2, s=start1 or start2 resp.
{
	struct node *cur = s;
	
	while(cur!=NULL)
	{
		printf("%d ",cur->val);
		cur = cur->addr;
	}
	printf("\n");
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
    concat(start1, start2);//concat both list
}

