#include <stdio.h> 
#include <stdlib.h> 
#define MAX 100
typedef struct tnode 
{ 
     struct tnode* left; 
     
     int info; 
    
     struct tnode* right; 
} tnode; 

/* A binary tree node has info, pointer to left child 
   and a pointer to right child */

 
void printPostorder(tnode* ptr);
void printPreorder(tnode* ptr);
void printInorder(tnode* ptr) ; 
 

tnode* createNode(int val) 
{ 
     tnode* new_Node = (tnode*) malloc(sizeof(tnode)); 
     
     if ( new_Node == NULL )
     {
     	printf("Print a msg\n");
     	exit(0);
     }
     
     new_Node->info = val; 
     new_Node->left = NULL; 
     new_Node->right = NULL; 
  
     return   (new_Node); 
} 
  

tnode* insert_recur(tnode* rptr, int val)
{
	/* If the tree is empty, return a new node */
	if (rptr==NULL)
	{	
		rptr=createNode(val);
		return rptr;
	}
	
	if (val < rptr->info)
		if (rptr->left!=NULL)
			insert_recur(rptr->left, val);
		else 
			rptr->left=createNode(val);
 	else 
	 	if (rptr->right==NULL)
			rptr->right=createNode(val);
		else 
			insert_recur(rptr->right, val);
			
	return rptr;
} 


tnode* insert_nonrecur(tnode* rptr, int val)
{
	/* If the tree is empty, return a new node */
	if (rptr == NULL) 
		rptr = createNode(val);
	else /* Otherwise, goto the node where it is to be inserted */
	{
		tnode *pp = NULL, *ptr=rptr ;
		
		while ( ptr )
		{
			pp=ptr;
			if (val< ptr->info)
				ptr=ptr->left;
			else
				ptr=ptr->right;
		}
		if (val < pp->info)
			pp->left=createNode(val);
		else
			pp->right=createNode(val);
	}
	
	return rptr;
	
} 
int max(int a,int b){
    if(a>b){
        return a;
    }
    else{
        return b;
    }
}
int height(tnode* root){
    tnode*ptr=root;
    if(ptr==NULL){
        return 0;
    }
    return 1+max(height(ptr->left),height(ptr->right));
}

int main() 
{ 
	tnode *root=NULL;
     
	root=insert_nonrecur(root,18);
	root=insert_nonrecur(root,21);
	root=insert_nonrecur(root,33);
	root=insert_nonrecur(root,567);
	root=insert_nonrecur(root,456);
	root=insert_nonrecur(root,-1);
    root=insert_recur(root,23);
	root=insert_recur(root,23);
	root=insert_recur(root,23);
	root=insert_recur(root,23);

	printf("\nPreorder traversal of binary tree is \n"); 
	printPreorder(root); 
    int heigh=height(root);
    printf("\n The height of the tree is %d",heigh);
	
	return 0; 
} 
/* Given a binary tree, print its nodes according to the 
  "bottom-up" postorder traversal. */
void printPreorder(tnode* ptr) 
{ 
     if (ptr == NULL) 
        return; 
  
     // now deal with the ptr 
     printf("%d ", ptr->info); 

     // first recur on left subtree 
     printPreorder(ptr->left); 
  
     // then recur on right subtree 
     printPreorder(ptr->right); 
  
     
}