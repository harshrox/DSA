// Double Order Traversal

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

void dot(struct node *t)
{
	if(t)
	{
		printf("%d ",t->data);
		dot(t->left);
		printf("%d ",t->data);
		dot(t->right);
		
	}
}

int main()
{
	struct node *root=NULL;
	root = insert(root,16);
	root = insert(root,12);
	root = insert(root,7);
	root = insert(root,14);
	root = insert(root,13);
	root = insert(root,25);
	root = insert(root,18);
	root = insert(root,27);
	root = insert(root,22);
	
	printf("Double Order Traversal=");
	dot(root);
	printf("\n");
	
	return 0;


}


