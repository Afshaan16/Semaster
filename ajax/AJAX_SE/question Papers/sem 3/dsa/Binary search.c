#include <stdio.h>
#define SIZE 50

int array[SIZE];

void b_search(int,int);// element to be found, no of elements

int main()
{
	int n,i,l;
	printf("Enter no of Elements: ");
	scanf("%d",&l);
	for(i=0;i<l;i++)
	{
		printf("Enter %d Element: ",i+1);
		scanf("%d",&array[i]);
	}
	printf("Enter Element to be searched: ");
	scanf("%d",&n);
	b_search(n,l);
	return 0;
}
void b_search(int n,int l)
{
	int i,first,last,middle;

	first = 0;
   	last = l - 1;
   	middle = (first+last)/2;
 
   	while (first <= last) 
	{
    if (array[middle] < n)
        first = middle + 1;    
    else if (array[middle] == n) 
	{
        printf("%d found at location %d.\n", n, middle+1);
        break;
    }
    else
        last = middle - 1;
 
    middle = (first + last)/2;
	}
   	if (first > last)
      printf("Not found! %d isn't present in the list.\n", n);
}
