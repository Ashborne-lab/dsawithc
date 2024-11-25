#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* next;
};

typedef struct node Node ;

 
void InsertBegSLL(Node **start_ptr, int val)
{
	Node * temp;
	temp= malloc (sizeof (Node ));
	if ( NULL == temp)
	{
		printf("Node is not cretaed, overflow in the linked list\n");
		return;
	}
	temp -> data = val;
	temp-> next = NULL ;
	if ((*start_ptr) == NULL)
	{
		(*start_ptr) = temp ;
        return;
	}
	else 
	{
		temp->next = (*start_ptr) ;
		(*start_ptr) = temp ;
	}
}

void InsertEndSLL(Node **start_ptr, int val){
    Node *temp=malloc(sizeof(Node));
    if(temp==NULL){
        printf("Empty list:\n");
    }
    temp->data=val;
    temp->next=NULL;
    if(*start_ptr==NULL){
        *start_ptr=temp;
        return;
    }
    Node *ptr=*start_ptr;
    while(ptr->next!=NULL){
        ptr=ptr->next;

    }
    ptr->next=temp;
}
void InsertInSortedSLL(Node **start_ptr, int val){
    Node *temp;
    temp=malloc(sizeof(Node));
    temp->data=val;
    temp->next=NULL;
  Node *ptr=*start_ptr;
  if(NULL==ptr){
   printf("Empty libnked list,ovwerfl;ow on linked list");
    return;
  }
  if(*start_ptr==NULL || (*start_ptr)->data >=val){
    temp->next=*start_ptr;
    *start_ptr=temp;
    return;
  }
  Node*prev=NULL;
  while(ptr->data<val && ptr->next!=NULL){
    prev=ptr;
    ptr=ptr->next;
  }
  temp->next=ptr;
  prev->next=temp;
}
void InsertValAfterLocSLL(Node **start_ptr, int val, Node * loc){
    Node *temp=malloc(sizeof(Node));
     if(NULL==temp){
        printf("Overflow in linked list\n");
        return;
    }
    temp->data=val;
    temp->next=NULL;
   
    Node *ptr=*start_ptr;
    int size=0;
    

temp->next = loc->next;
loc->next=temp;
}
int DeleteBegSLL(Node **start_ptr){
    Node *ptr=*start_ptr;
    if(NULL==ptr){
        printf("Overfow( ^ )");
       
    }
    int deleteditem= (*start_ptr)->data;
    if(ptr->next==NULL){
       printf("Empty linkled list");
    }
    
    *start_ptr=(*start_ptr)->next;
 return deleteditem;
}
int DeleteEndSLL(Node **start_ptr){

}
void DeleteValSLL(Node **start_ptr,int val){
    Node *ptr=*start_ptr;
    Node *preptr=NULL;
    if (NULL==ptr)
    {
        printf("Empty list('^')");
    }
    if(ptr->data==val){
        *start_ptr=ptr->next;
        return;
    }
    while(ptr!=NULL&&ptr->data!=val){
        preptr=ptr;
        ptr=ptr->next;
    }
    if(NULL==ptr){
        printf("Valuen not found.");
    }
    preptr->next=ptr->next;
    free(ptr);
}
void DeleteValInSortedSLL(Node **start_ptr,int val){
Node *ptr=*start_ptr;
if(NULL==ptr){
    printf("Empty linked list");
    return;
}
if(ptr->data == val){
    *start_ptr=(*start_ptr)->next;
    free(ptr);
    return;
}
Node *preptr=NULL;
while(ptr!=NULL && ptr->data!=val){
    preptr=ptr;
    ptr=ptr->next;
}
if(ptr==NULL){
    printf("Element not found.");
    return;
}
preptr->next=ptr->next;
free(ptr);
}
void DeleteAtLocSLL(Node **start_ptr, Node * loc){
Node *ptr=*start_ptr;

}



void PrintListSLL(Node *head)
{
	Node * ptr= head;
	while (ptr!=NULL)
	{
		printf ("%d\t-> ", ptr-> data);
		ptr = ptr -> next;
	}
    printf("NULL");
}
int  CountNodesSLL(Node *head){
    int count=0;
    if(NULL==head){
        printf("Empty linked list.");
    }
    while(head!=NULL){
        head=head->next;
        count++;
    }
    return count;
}
int  CountOfValSLL(Node *head, int val);

Node * SearchVal(Node *head, int val);
Node * SearchValInSorted(Node *head, int val);

void ReverseSLL(Node **start_ptr);




int main()
{
   Node *start=NULL;
   InsertEndSLL(&start, 2);
   InsertEndSLL(&start, 3);
   InsertEndSLL(&start, 5);
   InsertEndSLL(&start, 6);

printf("Insertion at end linked list:\n");
PrintListSLL(start);
InsertInSortedSLL(&start,4);
printf("Insertion at sorted linked list:\n");
PrintListSLL(start);
   InsertEndSLL(&start, 4);
   InsertEndSLL(&start, 0);
   InsertEndSLL(&start, 9);
   InsertEndSLL(&start, 1);
   printf("\nInsertion at end: \n ");
   PrintListSLL(start);
   printf("\n");
   printf("\ndeletion of value: \n");
   DeleteValSLL(&start,9);
   PrintListSLL(start);
   
   	InsertBegSLL(&start, 7);
	InsertBegSLL(&start, 17);
	InsertBegSLL(&start, -23);
	InsertBegSLL(&start, 89);
    printf("\nnsertion at begining:\n");
	PrintListSLL(start);
    Node *ptr =start;

    while(ptr!=NULL&& ptr->data != 5){
    ptr=ptr->next;

}
	InsertValAfterLocSLL(&start, 92, ptr);
   printf("\nAfter inserting  number 92 after 5\n");

    PrintListSLL(start);
    printf("\n after deletinh begining node\n");
    int item=DeleteBegSLL(&start);
    printf(" deleted - %d \n",item);
    PrintListSLL(start);
    DeleteValInSortedSLL(&start,7);
    printf("\n After deleting 7\n");
    PrintListSLL(start);
    int count=CountNodesSLL(start);
    printf("\n Number of nodes in linked list after following instructions is %d",count);
}