#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node* left;
	struct node* right;
};

struct node* newnode(int data) {
	struct node* node;

	node = (struct node*) malloc(sizeof(struct node));
	node->data = data;
	node->left = NULL;
	node->right = NULL;

	return(node);
}

int getheight(struct node* node) {
	int lh, rh;

	if(node == NULL)
		return 0;
	else
	{
		lh = getheight(node->left);
		rh = getheight(node->right);

		if(lh>rh)
			return (lh+1);
		else
			return (rh+1);
	}
}

void print_tree(struct node* node, int level) {
	if (node == NULL) {
		return;
	}
	else if (level == 1) {
		printf("%d	", node->data);
		return;
	}
	else if (level > 1) {
		print_tree(node->left, level-1);
		print_tree(node->right, level-1);
	}
}

void printlevelorder(struct node* root) {
	int height;

	height = getheight(root);
	printf("The height of tree is %d\n", height);

	for(int i = 1; i <= height; i++) {
		print_tree(root, i);
	}
}

int main() {
	struct node* t;

	t = newnode(33);
	t->left = newnode(44);
	t->right = newnode(55);
	t->left->left = newnode(66);
	t->left->right = newnode(44);
	t->right->left = newnode(12);

	printf("Printing tree in level order\n");
	printlevelorder(t);

	return(0);
}
	
