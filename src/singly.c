#include <stdio.h>
#include <stdlib.h>

struct node {
	int value;
	struct node* link;
};
struct node *head, *backup, *new = 0;
int flag = 0; 				// By default, indicates there is no first node

void add_value_to_list(int value) {
	new = (struct node*)malloc(sizeof(struct node));
	new->value = value;
	new->link = NULL;
	if(flag == 0) {
		backup = new;
		flag++;
	}
	else 
		head->link = new;
	head = new;
}

int main() {
	int number_of_nodes, index, value;
	
	printf("Enter the number of nodes you wish to have.\n");
	scanf("%d", &number_of_nodes);

	if (number_of_nodes <= 0) {
		printf("Please try again with valid number of nodes\n");
		return 1;
	}

	while(number_of_nodes--) {
		printf("Enter the value to add:");
		scanf("%d", &value);
		add_value_to_list(value);
	}

	printf("Values in the list are ...\n");

	while (backup != 0) {
		printf("%d\n", backup->value);
		backup = backup->link;
	}
	return 0;
}

		
	
