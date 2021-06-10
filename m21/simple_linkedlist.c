#include <stdio.h>
#include <stdlib.h>

struct Node {
	int value;
	struct Node *next;
};

void print_list(struct Node* node) {
	while (node != NULL) {
		printf("Value %d\n", node->value);
		node = node->next;
	}
}

int main() {
	struct Node* head = NULL;
	struct Node* second = NULL;
	struct Node* last = NULL;
	
	head = (struct Node*) malloc(sizeof(struct Node));
	second = (struct Node*) malloc(sizeof(struct Node));
	last = (struct Node*) malloc(sizeof(struct Node));

	head->value = 10;
	head->next = second;

	second->value = 20;
	second->next = last;
	second->next->value = 30;

	last->next = NULL;

	printf("The value of last is %d\n", last->value);
	print_list(head);
	
	return 0;
}
