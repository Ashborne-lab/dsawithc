#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node* next;
    struct node* prev;
}Node;
Node* createNode(int val){
    Node* newNode=malloc(sizeof(Node));
    if(newNode==NULL){
        printf("Node is not created");
        return NULL;
    }
    newNode->data=val;
    newNode->next=NULL;
    newNode->prev=NULL;
    return newNode;
}
Node *insertnodeBeg(Node *head,int val){
    Node* newNode=createNode(val);
    if(head==NULL){
       return newNode;
    }
   
    newNode->next=head;
    head->prev=newNode;
    head=newNode;
    return head;
}
Node *insertEndDll(Node *head ,int val){
    Node *newNode=createNode(val);
    if(head==NULL){
        return newNode;
    }
    Node *temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    newNode->prev=temp;
    temp->next=newNode;
    return head;
}
Node *insertKthNode(Node* head,int k,int val){
    Node* newNode=createNode(val);
    if(newNode==NULL){
        return NULL;
    }
    if(k==1){
        return insertnodeBeg(head,val);
    }
    int cnt=0;
    Node* knode=head;
    while(knode!=NULL){
        cnt++;
        if(cnt==k)break;
        knode=knode->next;
    }
    Node *prev=knode->prev;
    prev->next=newNode;  
    newNode->prev=prev; 
    knode->prev=newNode;
    newNode->next=knode;
   return head;
}
Node *deleteBegdll(Node*head){
    if(head==NULL||head->next==NULL){
        return NULL;
    }
    Node*temp=head;
    head=head->next;
    head->prev=NULL;
    temp->next=NULL;
    return head;
}
Node *deleteEnddll(Node *head){
    if(head==NULL||head->next==NULL){
        return NULL;
    }
    Node *temp=head;   
    while(temp->next!=NULL){       
        temp=temp->next;
    }
    temp->prev->next=NULL;
  free(temp);
  return head;
}
Node *deleteKthNode(Node* head,int k){
    if(head==NULL){
        return NULL;
    }
    int cnt=0;
    Node *knode=head;
    while(knode!=NULL){
        cnt++;
        if(cnt==k)break;
        knode=knode->next;
    }
    Node *prev=knode->prev;
    Node *front=knode->next;
    if(prev==NULL&&front==NULL){
        return NULL;
    }
    else if(prev==NULL){
        return deleteBegdll(head);
    }
    else if (front==NULL){
        return deleteEnddll(head);
    }
    prev->next=front;
    front->prev=prev;
    knode->next=NULL;
    knode->prev=NULL;
    free(knode);
    return head;
}
Node* reverseDLL(Node* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }
    Node* last = NULL;
    Node* curr = head;

    while (curr != NULL) {
        last = curr;
        Node* temp = curr->prev;
        curr->prev = curr->next;
        curr->next = temp;
        curr = curr->prev;
    }

    // After the loop, last will be pointing to the new head
    return last;
}
void printList(Node *head){
    while(head!=NULL){
        printf(" %d",head->data);
        head=head->next;
    }
    printf("\n");
}
int main(int argc, char const *argv[])
{
    Node *head=NULL;
   head= insertnodeBeg(head,4);
    head= insertnodeBeg(head,3);
     head= insertnodeBeg(head,2);
      head= insertnodeBeg(head,1);
       head= insertnodeBeg(head,0);
        
    printList(head);
    printf("\n Insertion at end: ");
    head=insertEndDll(head,5);
     head=insertEndDll(head,6);
      head=insertEndDll(head,7);
       head=insertEndDll(head,8);
        head=insertEndDll(head,9);
    printList(head);
   head= deleteEnddll(head);
   printList(head); 
   head=deleteKthNode(head,3);
   printf("\n After deleting kth node\n");
   head=deleteBegdll(head);
    printList(head);
    head=insertKthNode(head,1,0);
     head=insertKthNode(head,3,2);
    printf("\n After inserting at kth node\n");
    printList(head);
    printf("\n After reversing the list\n");
    head=reverseDLL(head);
    printList(head);
    return 0;
}
