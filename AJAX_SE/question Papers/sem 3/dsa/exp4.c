// convert infix expression to post fix expression
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define SIZE 50
char in[SIZE];
struct node{
	char data;
	struct node *addr;
};
struct node *top;
int length;// length of infix variable
int empty();// return 1 if stack is empty
void push(char);// push the char
char pop();// delete and returnh stack top

int main()
{
	int i;// loop variable
	// read infix expression
	printf("Infix:");
	gets(in);
	length=strlen(in);
	printf("Prefix:");
		for(i=0;i<length;i++)
		{
			switch(in[i])
			{
				case'^':
					while(  !empty()  &&  top->data=='^')
						printf("%c",pop());
					push(in[i]);
					break;
				case'/':
					while(  !empty()  &&  (top->data=='^' || top->data=='/') )
						printf("%c",pop());
					push(in[i]);
					break;
				case'*':
				case'+':
				case'-':
					while(  !empty()  &&(  top->data=='^'  ||  top->data=='/'  ||  top->data=='*' )  )
						printf("%c",pop());
					push(in[i]);
					break;
				case'(':
					push(in[i]);
					break;
				case')':
					while(  !empty()  &&  top->data==')')
						printf("%c",pop());
						if(!empty())
						pop();
					break;
				default:
					printf("%c",in[i]);
			}// end of switch
		}// end of for
	while(!empty())
		printf("%c",pop());
	getch();
}// end of main

int empty()
{
	if(top==NULL)
		return 1;
	else
		return 0;
}// end of empty

void push(char val)
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

char pop()
{
	char ch=NULL;
	if(!empty())
	{
		ch=top->data;
		top=top->addr;
	}
	return ch;
}// end of pop


