// convert infix expression to post fix expression & evaluation
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define SIZE 50


int main()
{
	int i;// loop variable
	// read infix expression
	printf("Infix:");
	gets(in);
	len=strlen(in);
	printf("postfix:");
		for(i=0;i<len;i++)
		{
			switch(in[i])
			{
				case'^':
					while(  !empty()  &&  top->data=='^')
						po[p++]=pop();
					push(in[i]);
					break;
				case'/':
					while(  !empty()  &&  (top->data=='^' || top->data=='/') )
						po[p++]=pop();
					push(in[i]);
					break;
				case'*':
				case'+':
				case'-':
					while(  !empty()  &&(  top->data=='^'  ||  top->data=='/'  ||  top->data=='*' )  )
						po[p++]=pop();
					push(in[i]);
					break;
				case'(':
					push(in[i]);
					break;
				case')':
					while(  !empty()  &&  top->data==')')
						po[p++]=pop();
						if(!empty())
						pop();
					break;
				default:
					po[p++]=in[i];
			}// end of switch
		}// end of for
	while(!empty())
		po[p++]=pop();
	po[p]='\0';
	puts(po);
	//evaluation of postfix expression (converted)
	eval();
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

void eval()
{
	int i;
	float op1, op2, val;
	for(i=0;i<len;i++)
		{
			switch(po[i])
			{
				case'^':
					op1=fpop();
					op2=fpop();
					fpush(pow(op2,op1));
				break;
				case'/':
					op1=fpop();
					op2=fpop();
					fpush(op2/op1);
				break;
				case'*':
					op1=fpop();
					op2=fpop();
					fpush(op2*op1);
				break;
				case'+':
					op1=fpop();
					op2=fpop();
					fpush(op2+op1);
				break;
				case'-':
					op1=fpop();
					op2=fpop();
					fpush(op2-op1);
				break;
				default:
					printf("Value of %c: ",po[i]);
					scanf("%f",&val);
					fpush(val);
			}// end of switch
		}// end of for
	printf("Answer is: %f",fpop());
}

void fpush(float val)
{
	struct fnode *temp;
	temp=(struct fnode*)malloc(sizeof(struct fnode));
	temp->data=val;
	temp->addr=NULL;
		if(ftop!=NULL)
		{
			temp->addr=ftop;
		}
		ftop=temp;
}// end of fpush

float fpop()
{
	char ch=0.0;
	if(ftop!=NULL)
	{
		ch=ftop->data;
		ftop=ftop->addr;
	}
	return ch;
}// end of fpop



