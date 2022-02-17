#include <stdio.h>
#include <stdlib.h> //contain malloc function

struct Node
{
	int data;
	struct Node* next;
};

//Below function print data in structure
void Visit(struct Node* lptr)
{
	printf("%d ",lptr->data);
}

//Below function insert node at start with data d and return updated list pointer
struct  Node* InsertAtStart(int d, struct Node* lptr)
{
	struct Node* nptr;
	
	nptr=(struct Node*) malloc(sizeof(struct Node));
	nptr->data=d;
	nptr->next=lptr;
	lptr=nptr;
	
	return lptr;
}

struct Node* CreateList(int sum)
{
	struct Node* lptr;
	lptr=NULL;
	
	while(sum!=0)
	{
		lptr=InsertAtStart(sum%10,  lptr);
		sum=sum/10;
	}
	return lptr;
}

//Below function travel through the list
void TraverseList(struct Node* lptr)
{
	printf("\nLinked list is : ");
	while(lptr!=NULL)
	{
		Visit(lptr);
		lptr=lptr->next;
	}
}

int GetNumber(struct Node* lptr)
{	
	int num=0;
	while(lptr!=NULL)
	{
		num=num*10+ (lptr->data) ;	
		lptr=lptr->next;
	}
	return num;
}
	
//Below function delete whole list
void DeleteList( struct Node* lptr)
{
	struct Node* nptr;
	nptr=lptr;
	
	while(nptr!=NULL)
	{
		lptr=lptr->next;
		free(nptr);
		nptr=lptr;
	}
}

int main()
{
	struct Node* list_ptr1=NULL,* list_ptr2=NULL;

	list_ptr1=InsertAtStart(3, list_ptr1);
	list_ptr1=InsertAtStart(4, list_ptr1);
	list_ptr1=InsertAtStart(2, list_ptr1);
	
	list_ptr2=InsertAtStart(4, list_ptr2);
	list_ptr2=InsertAtStart(6, list_ptr2);
	list_ptr2=InsertAtStart(5, list_ptr2);
	
	//traverse list 1 elements
	TraverseList(list_ptr1);
	
	//traverse list 2 elements
	TraverseList(list_ptr2);
	
	int x,y,sum;
	
	x=GetNumber(list_ptr1);
	y=GetNumber(list_ptr2);
	
	sum=x+y;
	
	struct Node* list_ptr3=CreateList(sum);
	
	//traverse list 3 elements
	TraverseList(list_ptr3);
	
	//delete complete list
	DeleteList(list_ptr1);
	DeleteList(list_ptr2);
	DeleteList(list_ptr3);
	
	return 0;
}
