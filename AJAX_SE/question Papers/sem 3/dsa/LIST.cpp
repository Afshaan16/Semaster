#include<stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *add;
};
 struct node *start;
 
 void ins(int);
 void search(int);
 void disp();
 void del(int);
  
  int main()
  {ins(10);
  ins(20);
  ins(30);
  ins(5);
  search(5);
  search(3);
  search(89);
  del(20);
  }
  
  void ins(int val)
  { struct node *temp,*cur,*prev;
    temp=(struct node *)malloc(sizeof(struct node));
    temp->data=val;
    temp->add=NULL;
    
    //case 1
    if(start==NULL)
    {start=temp;
	}
	else //case 2
	{cur=start;
	 prev=NULL;
	 while(cur!=NULL && cur->data<val)
	 { prev=cur;
	   cur=cur->add;
	 }
	 temp->add=cur;
	 if(prev!=NULL)
	 prev->add=temp;
	 else
      start=temp;
} disp();
	}
	
	
	void disp()
	{ struct node *i;
	  i=start;
	  printf("linked list\n");
	  while(i!=NULL)
	  {  printf("%d ",i->data);
	      i=i->add;
	       printf("\n");
	  } 
	 
	}
    
 
   void search(int search)
   { struct node *i;
     i=start;
     while(i!=NULL)
     { if(i->data==search)
       {
	   printf("found\n");
       return;
   }
	 
	 i=i->add;
   }
 printf("not found\n");
}

 




	void del(int x)
{
	struct node *cur, *prev;
	cur = start;
	prev = start;
	while(cur->data!=x && cur!=NULL)
	{
		prev = cur;
		cur = cur->add;
	}
	if(cur == NULL)
		printf("Error : %d not found\n",x);
	else if(cur == start)
		start = cur->add;
	else
		prev->add = cur->add;
	disp();
}
 
 
 
 
 
 
 
 
 
