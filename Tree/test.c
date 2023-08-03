

// Recursive approach of BST

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

struct node *insert(struct node *root, int data)
{
	if(root==NULL)
	{
		return newnode(data);
	}
	else if(data<root->data)
	{
		root->left=insert(root->left,data);
	
	}
	else
	{
		root->right=insert(root->right,data);
	}
	return root;


}


void addGreaterUtil(struct node *root, int *sum_ptr)
{
    // Base Case
    if (root == NULL)
        return;
 
    // Recur for right subtree first so that sum of all greater
    // nodes is stored at sum_ptr
    addGreaterUtil(root->right, sum_ptr);
 
    // Update the value at sum_ptr
    *sum_ptr = *sum_ptr + root->data;
 
    // Update key of this node
    root->data = *sum_ptr;
 
    // Recur for left subtree so that the updated sum is added
    // to smaller nodes
    addGreaterUtil(root->left, sum_ptr);
}
 
// A wrapper over addGreaterUtil().  It initializes sum and calls
// addGreaterUtil() to recursivel upodate and use value of sum
void addGreater(struct node *root)
{
    int sum = 0;
    addGreaterUtil(root, &sum);
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

	struct node *root=NULL;
	root = insert(root,5);
	root = insert(root,2);
	root = insert(root,1);
	root = insert(root,3);
	root = insert(root,8);
	root = insert(root,7);
	root = insert(root,9);
	
	
	
	
    
    printf("In-order=");
    inorder(root);
    printf("\n");
    
    addGreater(root);
 
	printf("In-order=");
    inorder(root);
    printf("\n");

	return 0;

}