#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node* left;
	struct node* right;
};

struct node* newnode(int data) {
	struct node* node;
	
	node = (struct node*) malloc (sizeof(struct node));
	node->data = data;
	node->left = NULL;
	node->right = NULL;

	return node;
}

void print_inorder(struct node* node) {
	if (node == NULL)
		return;
	else
	{
		print_inorder(node->left);
		printf("%d ", node->data);
		print_inorder(node->right);
	}
}

void print_preorder(struct node* node) {
	if (node == NULL)
		return;
	else {
		printf("%d ", node->data);
		print_preorder(node->left);
		print_preorder(node->right);
	}
}

void  print_postorder(struct node* node) {
	if (node == NULL)
		return;
	else {
		print_postorder(node->left);
		print_postorder(node->right);
		printf("%d ", node->data);
	}
}

void print_tree_breadthfirst(struct node* node, int level) {

	if (node == NULL)
		return;
	else if (level == 1) {
		printf("%d ", node->data);
		return;
	}
	else if (level > 1) {
		print_tree_breadthfirst(node->left, level-1);
		print_tree_breadthfirst(node->right, level-1);
	}
}

int getheight(struct node* node) {
	int lh, rh;	

	if (node == NULL)
		return 0;
	else {
		lh = getheight(node->left);
		rh = getheight(node->right);

		if (lh > rh)
			return (lh+1);
		else
			return (rh+1);
	}
}

void print_breadthfirst(struct node* node) {
	int height;

	height = getheight(node);
	for(int i=1; i<=height; i++)
		print_tree_breadthfirst(node, i);
}

int main() {
	struct node* root;

	root = newnode(1);
	root->left = newnode(2);
	root->right = newnode(3);
	root->left->left = newnode(4);
	root->left->right = newnode(5);

	printf("\nInorder: ");
	print_inorder(root);

	printf("\nPreorder: ");
	print_preorder(root);

	printf("\nPostorder: ");
	print_postorder(root);

	printf("\nBreadth First: ");
	print_breadthfirst(root);
	printf("\n");
	
	return 0;
}
	
