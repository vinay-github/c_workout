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

struct node* construct_tree(int pre[], int *preindex, int low, int high, int size) {
	if (*preindex >= size || low>high) 
		return NULL;

	struct node* node = newnode(pre[*preindex]);
	*preindex += 1;

	if (low==high)
		return node;

	int i;
	for(i=low; i<=high; i++) {
		if (pre[i] > node->data)
			break;
	}

	node->left = construct_tree(pre, preindex, *preindex, i-1, size);
	node->right = construct_tree(pre, preindex, i, high, size);

	return node;
}

void print_inorder(struct node* node) {
	if (node == NULL)
		return;

	print_inorder(node->left);
	printf("%d ", node->data);
	print_inorder(node->right);
}

struct node* construct_inorder(int pre[], int size) {
	int preindex = 0;
	return construct_tree(pre, &preindex, 0 , size-1, size);
}

int main() {
	int pre[] = { 10,5,1,7,40,50 };
	int size = sizeof(pre)/sizeof(pre[0]);

	struct node* root = construct_inorder(pre, size);
	print_inorder(root);
	printf("\n");
	
	return 0;
}
	
