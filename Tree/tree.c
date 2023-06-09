// Binary Tree

#include<stdio.h>
#include<stdlib.h>

struct node
{
    struct node *left;
    int data;
    struct node *right;
};

struct node *newnode(int data)
{
    struct node *new = (struct node*)malloc(sizeof(struct node));
    new->data=data;
    new->left=NULL;
    new->right=NULL;
    return new;
}

void inorder(struct node *t)
{  
	if(t)
	{
		inorder(t->left);
		printf("%d ",t->data);
		inorder(t->right);
	}
	
}
void preorder(struct node *t)
{  
	if(t)
	{	
		printf("%d ",t->data);
		preorder(t->left);
		preorder(t->right);
	}
	
}
void postorder(struct node *t)
{  
	if(t)
	{
		postorder(t->left);
		postorder(t->right);
		printf("%d ",t->data);
	}
	
}
int main()
{
    struct node *root= newnode(16);
    
    root->left=newnode(12);
    root->left->left=newnode(9);
    root->left->right=newnode(3);
    
    root->left->right->left=newnode(2);
    
    root->right=newnode(19);
    root->right->left=newnode(18);
    root->right->right=newnode(11);
    
    root->right->left->right=newnode(5);
    
    printf("Pre-order=");
    preorder(root);
    printf("\n");
    
    printf("In-order=");
    inorder(root);
    printf("\n");
    
    printf("Post-order=");
    postorder(root);
    printf("\n");
    
    return 0;

}
