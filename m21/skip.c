#include <stdio.h>
#include <stdlib.h>

struct node {
	int value;
	struct node* next;
};

void skip(struct node** node, int batch_size, int delete_size) {

	struct node* copy_node = *node;
	struct node* backup_head = NULL;
	struct node* thead = NULL, *tnode=NULL;

	int temp = batch_size - delete_size;
	int i = 0;
	int flag = 0;

	while(copy_node != NULL) {
		if(i==delete_size) {
			if(flag == 0) {
				backup_head = copy_node;
				flag = 1;
			}		
	
			if (thead) {
				thead->next=copy_node;
				copy_node = thead;
			}
			for(int j=0; j<batch_size && copy_node!=NULL; j++) {
				thead = copy_node;
				copy_node = copy_node->next;
			}
			i = 0;
			continue;
		}
		tnode = copy_node->next;
		free(copy_node);
		copy_node=tnode;
		i++;
	}
	*node = backup_head;
}

struct node* newnode(int value) {
	struct node* node = (struct node*)malloc(sizeof(struct node));
	node->value = value;
	node->next = NULL;

	return node;
}

void print_list(struct node* root) {
	while(root!=NULL) {
		printf("%d ", root->value);
		root = root->next;
	}
}

int main() {
	struct node* root = NULL;

	root = newnode(32);
	root->next = newnode(35);
	root->next->next = newnode(36);
	root->next->next->next = newnode(63);
	root->next->next->next->next = newnode(43);
	root->next->next->next->next->next = newnode(13);
	root->next->next->next->next->next->next = newnode(23);
	root->next->next->next->next->next->next->next = newnode(33);
	root->next->next->next->next->next->next->next->next = newnode(333);
	root->next->next->next->next->next->next->next->next->next = newnode(233);
	root->next->next->next->next->next->next->next->next->next->next = newnode(343);
	
	print_list(root);
	printf("\n");
	skip(&root, 4, 2);
	print_list(root);
	printf("\n");

	return 0;
}














