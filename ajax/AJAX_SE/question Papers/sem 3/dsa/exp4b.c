// evaluation for postfix
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define SIZE 50
char po[SIZE];// to hold postfix expression
struct node
{
	float data;
	struct node *addr;	
};
struct node *top;

struct node *temp;

float pop();
void push(float);
int empty();

int main()
{
	int i,len;
	float op1,op2,val;
	// read infix expression
	// convert top postfix expression
	printf("postfix:");
	gets(po);
	len=strlen(po);
	// read updated postfix from l->R per symbol
		for(i=0;i<len;i++)
		{
			switch(po[i])
			{
				case'^':
					op1=pop();
					op2=pop();
					push(pow(op2,op1));
				break;
				case'/':
					op1=pop();
					op2=pop();
					push(op2/op1);
				break;
				case'*':
					op1=pop();
					op2=pop();
					push(op2*op1);
				break;
				case'+':
					op1=pop();
					op2=pop();
					push(op2+op1);
				break;
				case'-':
					op1=pop();
					op2=pop();
					push(op2-op1);
				break;
				default:
					printf("Value of %c: ",po[i]);
					scanf("%f",&val);
					push(val);
			}// end of switch
		}// end of for
printf("Answer is: %f",pop());
}// end of main

int empty()
{
	if(top==NULL)
		return 1;
	else
		return 0;
}// end of empty

void push(float val)
{
	struct node *temp;
	temp=(struct node*)malloc(sizeof(struct node));
	temp->data=val;
	temp->addr=NULL;
		if(empty())
		{
			top=temp;
		}
		else
		{
			temp->addr=top;
			top=temp;
		}
}// end of push

float pop()
{
	char ch=0.0;
	if(!empty())
	{
		ch=top->data;
		top=top->addr;
	}
	return ch;
}// end of pop


