#include<stdio.h>
#include<stdlib.h>

struct node
{
	int value;
	struct node *left,*right;
};

struct node* insert(struct node *, int );
int delete(struct node *, int );
void inorder(struct node *);
void preorder(struct node*);
void postorder(struct node *);

int main()
{
	int i,val,n;
	printf("Enter no. of elements: ");
	scanf("%d",&n);
	struct node *root=NULL;
	printf("Enter %d elements: \n",n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&val);
		root=insert(root,val);
	}
	printf("Inorder traversal: ");
	inorder(root);
	printf("\nPreorder traversal: ");
	preorder(root);
	printf("\nPostorder traversal: ");
	postorder(root);
	return 0;
}

struct node* insert(struct node *root,int data)
{
	if(root==NULL)
	{
		struct node *tmp=(struct node*)malloc(1*sizeof(struct node ));
        	tmp->value=data;
        	tmp->right=NULL;
        	tmp->left=NULL;
		return tmp;
	}
	if(data<=root->value)
		root->left=insert(root->left,data);
	else
		root->right=insert(root->right,data);
	return root;
}

void inorder(struct node *root)
{
	if(root!=NULL)
	{
		inorder(root->left);
		printf("%d ",root->value);
		inorder(root->right);
	}

}

void preorder(struct node *root)
{
	if(root!=NULL)
	{
		printf("%d ",root->value);
		preorder(root->left);
		preorder(root->right);
	}
}

void postorder(struct node *root)
{
	if(root!=NULL)
	{
		postorder(root->left);
		postorder(root->right);
		printf("%d ",root->value);
	}
}

