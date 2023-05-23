// Iterative approach of BST


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
    
    if(12<root->data)
    {
    	root->left=newnode(12);

    }
    else
    {
    	root->right=newnode(12);
    }
    
    
    if(7<root->left->data)
    {
    	root->left->left=newnode(7);

    }
    else
    {
    	root->left->right=newnode(7);
    }
    
    
    if(14<root->left->data)
    {
    	root->left->left=newnode(14);

    }
    else
    {
    	root->left->right=newnode(14);
    }
    
    
    if(25<root->data)
    {
    	root->left=newnode(25);

    }
    else
    {
    	root->right=newnode(25);
    }
    
    
    
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
