#include <stdio.h>
#include <stdlib.h>

struct node {
	int value;
	struct node* next;
};

struct node* get_node();
void insertion_end(struct node**, int);
void insertion_loc(struct node**, int, int);
void insertion_begin(struct node*);
void print_list(struct node**);

int main() {
	int input, value;
	struct node *head = NULL;
	struct node *add = NULL;
	int num;

again:
	printf("1. Insertion at the end.\n2. Insertion after a give node.\n3. Insertion at the begining.\n");
	scanf("%d", &input);

	switch(input) {
		case 1:
			printf("Enter the value: ");
			scanf("%d", &value);
			insertion_end(&head, value);
			print_list(&head);
			goto again;
			break;

		case 2:
			printf("Enter the value: ");
			scanf("%d", &value);
			printf("Enter after how many nodes you want to insert: ");
			scanf("%d", &num);
			insertion_loc(&head, value, num);
			print_list(&head);
			goto again;
			break;

		case 3:
			printf("Insertion at the begining\n");
			goto again;
			break;

		default:
			printf("Invalid entry\n");
			return -1;

	}

	return 0;
}

void insertion_end(struct node** head, int value) {
	struct node* new_node;
	struct node* temp = *head;

	new_node = (struct node*)malloc(sizeof(struct node));
	new_node->value = value;
	new_node->next = NULL;

	if (*head == NULL) {
		*head = new_node;
		return;
	}
	
	while (temp->next != NULL) {
		temp = temp->next;
	}

	temp->next = new_node;
}

void insertion_loc(struct node** head, int value, int num) {
	struct node* temp = *head;
	struct node* newnode = (struct node*)malloc(sizeof(struct node));
	int count = 0;

	if(temp == NULL && num != 1) {
		printf("Location not found\n");
		return;
	}
	
	while (count != num) {
		temp = temp->next;
		count++;
	}

	newnode->value = value;
	
	if (temp !=NULL) {
		newnode->next = temp->next;
		temp->next = newnode;
	}
	else {
		newnode->next = NULL;
		temp = newnode;
	}
}

void print_list(struct node** head) {
	struct node* temp = *head;
	printf("Printing\n");
	while (temp!=NULL) {
		printf("%d\n", temp->value);
		temp = temp->next;
	}
} 
