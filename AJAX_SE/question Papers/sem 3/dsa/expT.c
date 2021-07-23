//expression tree from postfix
//using stack (array)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 20

struct node * stack[MAX];
int stackTop=0;

char po[MAX];
int l;

struct node{
	char data;
	struct node *left;
	struct node *right;
};
struct node *root;

int stackEmpty()
{
	if(stackTop==0)
		return 1;
	else
		return 0;
}

void dispStack()
{
	int i;
	printf("stack:");
	for(i=0; i<stackTop; i++)
	{
		printf("%p ",stack[i]);
	}
	printf("\n");
}
void push(char val, struct node *addr)
{
	struct node *temp;
	
	if(val!='\0')
	{
		temp=(struct node *)malloc(sizeof(struct node));
		temp->data=val;
		temp->left=NULL;
		temp->right=NULL;
	}
	else
	{
		temp=addr;
	}
	stack[stackTop++]=temp;
	//dispStack();
}

struct node * pop()
{
	struct node *x=NULL;
	if(!stackEmpty())
	{
		x=stack[stackTop-1];
		stackTop--;
	}
	//printf("popped %p\n",x);
	return x;
}

//value, self addr, parent addr, left/right child of parent
struct node * ins(char val, struct node *self, struct node *parent, int l)
{
	struct node *temp;
	
	//printf("insert(%c, %p, %p, %d)\n",val,self,parent,l);
	
	if(val!='\0')
	{
		temp=(struct node *)malloc(sizeof(struct node));
		temp->data=val;
		temp->left=NULL;
		temp->right=NULL;
	}
	
	root=parent;
		
	if(parent!=NULL)
	{
		if(l)
		{
			parent->left=self;
		}
		else
			parent->right=self;
	}
	return temp;
}// end of insert function.

void disp(struct node *curr,int lev)
{
	//printf("disp(%c, %p, %p, %p)\n",curr->data,curr,curr->left,curr->right);
	int i;
	for(i=1;i<=lev;i++)
	{
		printf("\t");
	}
	printf("%c",curr->data);
	printf("\n");
	if(curr->left!=NULL)
	{
		printf("(L)");
		disp(curr->left,lev+1);
	}
	if(curr->right!=NULL)
	{
		printf("(R)");
		disp(curr->right,lev+1);
	}
}// end of display function.

int main()
{
	int i;
	struct node *op1, *op2;
	struct node *parent;
	
	printf("postfix:");//read postfix
	gets(po);
	l=strlen(po);//find length
	for(i=0;i<l;i++)//construct expression tree by reading postfix expression L->R
	{
		if(po[i]=='+' || po[i]=='-' || po[i]=='/' || po[i]=='*' || po[i]=='^'  )//if operator
		{
			op1=pop();//pop 2 operands
			op2=pop();
			parent = ins(po[i],NULL,NULL,0);//push back subtree
			//printf("parent:%p\n",parent);
			ins('\0',op1,parent,0);
			ins('\0',op2,parent,1);
			push('\0',parent);
		}
		else//if operand
		{
			push(po[i],NULL);//store addr in stack, create new node there
		}
	}	
	disp(stack[0],0);
	
}


