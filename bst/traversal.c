#include <stdio.h> 
#include <stdlib.h> 
  #define MAX 100
  int top=-1;
  void* stack[MAX];
  void* push(void* val){
     if(top==MAX-1){
          printf("Stack is full\n");
        exit(0) ;
     }
     stack[++top]=val;
  }
  void* pop(){
     if(top==-1){
          printf("Empty stack\n");
          return NULL;
     }
     
     return stack[top--];
  }
  void* peek(){
     if(top==-1){
          printf("Empty stack\n");
          return NULL;
     }
     
     return stack[top];
  }
  

typedef struct tnode 
{ 
     struct tnode* left; 
     
     int info; 
    
     struct tnode* right; 
} tnode; 


tnode* createNode(int val) 
{ 

     tnode* new_Node = (tnode*) malloc(sizeof(tnode)); 
     if ( new_Node == NULL )
     {
     	printf("\nNode has not been created so terminating program\n");
     	exit(0);
     }
     new_Node->info = val; 
     new_Node->left = NULL; 
     new_Node->right = NULL; 
  
     return(new_Node); 
}



void iterativepreorder(tnode* ptr){
if(ptr==NULL)return;
push(ptr);
while(top!=-1){
    tnode* current=(tnode*)pop();
     printf("%d ", current->info);
    if(current->right!=NULL)push(current->right);
    if(current->left!=NULL)push(current->left);
}


}
void iterativeinorder(tnode* ptr){
     if(ptr==NULL)return ;
tnode* node=ptr;
while(1){
     if(node!=NULL){
          push(node);
          node=node->left;
     }
     else{
          if(top==-1)break;
          node=(tnode*)pop();
          printf("%d ",node->info);
          node=node->right;
     }
}
}
void iterativepostorder(tnode* ptr){
  if(ptr==NULL)return;
  tnode* curr=ptr;
tnode* lastVisited=NULL;

  while(curr!=NULL || top!=-1){
     if(curr!=NULL){
          push(curr);
          curr=curr->left;
     }
    else {
            tnode* peekNode = (tnode*)peek();
            if (peekNode->right != NULL && lastVisited != peekNode->right) {
                curr = peekNode->right;
            } else {
                printf("%d ", peekNode->info);
                lastVisited = (tnode*)pop();
            }
        }
    }
}
  
void printPreorder(tnode* ptr);
void printPostorder(tnode* ptr);
void printInorder(tnode* ptr); 


/* Driver program to test above functions*/
int main() 
{ 
     tnode *root=NULL;
     
     root = createNode(1); 
     root->left    = createNode(2); 
     root->right   = createNode(3); 
     root->left->left    = createNode(4); 
     root->left->right   = createNode(5);  
  
     printf("\nPreorder traversal of binary tree is \n"); 
     printPreorder(root); 
       printf("\n Iterative Preorder traversal of binary tree is \n"); 
     iterativepreorder(root);
  
     printf("\nInorder traversal of binary tree is \n"); 
     printInorder(root);   
  printf("\n Iterative Inorder traversal of binary tree is \n"); 
      iterativeinorder(root); 
     printf("\nPostorder traversal of binary tree is \n"); 
     printPostorder(root); 
   printf("\n Iterative postorder traversal of binary tree is \n"); 
  iterativepostorder(root);
     return 0; 
} 

/* Given a binary tree, print its nodes in preorder*/
void printPreorder(tnode* ptr) 
{ 
     if (ptr == NULL) 
          return; 
  
     /* first print info of ptr */
     printf("%d ", ptr->info);   
  
     /* then recur on left sutree */
     printPreorder(ptr->left);   
  
     /* now recur on right subtree */
     printPreorder(ptr->right); 
}     

/* Given a binary tree, print its nodes in inorder*/
void printInorder(tnode* ptr) 
{ 
     if (ptr == NULL) 
          return; 
  
     /* first recur on left child */
     printInorder(ptr->left); 
  
     /* then print the info of ptr */
     printf("%d ", ptr->info);   
  
     /* now recur on right child */
     printInorder(ptr->right); 
} 



/* Given a binary tree, print its nodes according to the 
  "bottom-up" postorder traversal. */
void printPostorder(tnode* ptr) 
{ 
     if (ptr == NULL) 
        return; 
  
     // first recur on left subtree 
     printPostorder(ptr->left); 
  
     // then recur on right subtree 
     printPostorder(ptr->right); 
  
     // now deal with the ptr 
     printf("%d ", ptr->info); 
}