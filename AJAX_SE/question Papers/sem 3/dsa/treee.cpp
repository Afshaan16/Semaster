#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
# define max 20
struct node{
	struct node *left;
	struct node *right;
	int visited;
	int data;
};
int x=0;
struct node *root;
struct node *q[max];
void display(struct node *,int);
void ins(struct node *,int);
void bfs(int);
int main()
{
	printf("Root ");
	ins(NULL,0);
	display(root,0);
	q[x++]=root;
//	bfs(15);
}
void ins(struct node *parent,int l)
{
	int val;
	struct node *temp;
	char ch;
	printf("value of Node: ");
	scanf("%d",&val);
	temp=(struct node *)malloc(sizeof(struct node));
	temp->data=val;
	temp->left=NULL;
	temp->right=NULL;
	temp->visited=0;
	if(root==NULL)
		root=temp;
	if(parent!=NULL)
	{
		if(l)
		{
			parent->left=temp;
		}
		else
			parent->right=temp;
	}
	printf("Left Child of (%d) ? (Y/N): ",val);
	ch=getche();
	printf("\n");
	if(ch=='y' || ch=='Y')
	ins(temp,1);
	printf("Right Child of (%d) ? (Y/N): ",val);
	ch=getche();
	printf("\n");
	if(ch=='y' || ch=='Y')
	ins(temp,0);
}// end of insert function.
void display(struct node *curr,int lev)
{
	int i;
	for(i=1;i<=lev;i++)
	{
		printf("\t");
	}
	printf("%d",curr->data);
	printf("\n");
	if(curr->left!=NULL)
	{
		printf("(L)");
		display(curr->left,lev+1);
	}
	if(curr->right!=NULL)
	{
		printf("(R)");
		display(curr->right,lev+1);
	}

}// end of display function.
void bfs(int val)
{
	int i;
	do
	{
		if(q[0]->data==val)
		{
			printf("\nFound.\n");
			return;
		}
		else
		{
			q[0]->visited=1;
			if(q[0]->left && (q[0]->left)->visited==0)
				q[x++]=q[0]->left;
			if(q[0]->right && (q[0]->right)->visited==0)
				q[x++]=q[0]->right;
			for(i=0;i<x-1;i++)
			{
				q[i]=q[i+1];
			}
			x--;
		}
	}while(x>0); // end of do while.
	printf("\nNot Found.");
}// end of bfs.
