#define SIZE 5
#include<stdio.h>

int q[SIZE];
int r=0;
int f=0;

int q_full();
int q_empty();
void insert(int);
void del();
void display();

int main()
{
	int choice,val;
	do
	{
		printf("\n1. Insert\n2. Delete\n3. Display\n4. Exit");
		printf("\nEnter your choice - ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				printf("Enter the value to insert - ");
				scanf("%d",&val);
				insert(val);
				break;
			case 2:
				del();
				break;
			case 3:
				display();
				break;
			case 4:
				break;
		}
	}
		while(choice!=4);
}

int q_full()
{
	 if(r==SIZE)
	 return 1;
	 else
	 return 0;
}

int q_empty()
{
	if(r==0)
	return 1;
	else
	return 0;
}

void insert(int val)
{
	if(q_full())
	printf("Error! Queue full");
	else
	{
		q[r]=val;
		r++;
		display();
	}
}

void del()
{
	int i;
	if(q_empty())
	printf("Error! Queue empty");
	else
	{
		printf("Element remove is : %d\n",q[f]);
		for(i=0;i<r-1;i++)
		{
			q[i]=q[i+1];
		}
		r--;
		display();
	}
}

void display()
{
	int i;
	printf("Queue : ");
	for(i=0;i<r;i++)
	{
		printf("%d ",q[i]);
	}
	printf("\n");
}
