#include<stdio.h>
#define SIZE 5

int storage[SIZE];
void ins();
void disp();
void search();

int count=0;
int main()
{
	int choice;
	do
	{
		printf("1. Insert\t2. Display\t3. Search\t4. Any key to Exit.\n");
		printf("Choice: ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: ins();	disp();	break;
			case 2: disp();		break;
			case 3: search();	break;
			default:choice=0;
		}// end of switch
	}while(choice!=0);// end of do while
}
void ins()
{
	int n,i,j;
	if(count!=SIZE)
	{
		printf("value: ");
		scanf("%d",&n);
		i=n%SIZE;
		printf("Index = %d %% %d = %d\n",n,SIZE,i);
		if(storage[i]!=0)
		{
			printf("Collision\n");
			for(j=i+1;j<SIZE;j++)
			{
				if(storage[j]==0)
				{
					storage[j]=n;
					break;
				}
			}
			if(j==SIZE)
			{
				for(j=0;j<i;j++)
				{
					if(storage[j]==0)
					{
						storage[j]=n;
						break;
					}
				}
			}
		}
		else
			storage[i]=n;
		count++;
	}
	else
	{
		printf("Error: Storage FULL\n");
	}
}

void disp()
{
	int i;
	printf("Storage: ");
	for(i=0;i<SIZE;i++)
	{
		printf("%d ",storage[i]);
		
	}
	printf("\n\n");
}

void search()
{
	int key,i,j,h=0;
	printf("Search Element: ");
	scanf("%d",&key);
	i=key%SIZE;
	if(storage[i]==key)
		h=1;
	else
	{
		for(j=i+1;j<SIZE;j++)
		{
			if(storage[j]==key)
			{
				h=1;
				break;
			}
			if(storage[j]==0)
			{
				break;
			}
		}
		if(j==SIZE)
		{
			for(j=0;j<i;j++)
			{
				if(storage[j]==key)
				{
					h=1;
					break;
				}
				if(storage[j]==0)
				{
					break;
				}
			}
		}
	}
	if(h)
		printf("Element found!\n");
	else
		printf("Element not found!\n");
	printf("\n");
}
