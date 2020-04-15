#include <stdio.h>
#include <stdlib.h>

/* The datastructure to store each node in DLL*/
typedef struct node{
	char data;
	struct node* right;
	struct node* left;
}node;

void insert(node* head, char data){
	// TODO: Insert a node at a position
	// Create the node
	node* new_node = (node*)malloc(sizeof(node));
	new_node->data = data;
	new_node->left = NULL;
	new_node->right = NULL;

	// Create a pointer to tail through the list
	node* ptr =  head;

	// Insert the node at end of the list
	while(ptr->right!=NULL){
		ptr = ptr->right;
	}

	ptr->right = new_node;
}

void display(node* head){
	node* ptr = head;
	while(ptr!=NULL){
		printf("%c\n", ptr->data);
		ptr = ptr->right;
	}
}

node* delete(node* head, char data){
	node* next = head->right;
	node* curr = head;

	// Element to delete is in the first node
	if(head->data == data){
		return head->right;
	}

	while(next!=NULL){
		if (next->data == data){
			curr->right = next->right;
			next->right = NULL;
			return head;
		}
		curr = curr->right;
		next = next->right;
	}

	printf("Data %c not found :/", data);
}
void main(){
	int choice;
	char data;
	printf("----------- DLL for mutable strings ------------\n");

	// Create a head pointer for the DLL
	node* head = (node*)malloc(sizeof(node));

	while(choice!=5){
		printf("\n\nPlease chose one of the options\n");
		printf("1. Display the string\n");
		printf("2. Insert a Character\n");
		printf("3. Delete a Character\n");
		printf("4. Find a Character\n");
		printf("5. Exit\n");

		scanf("%d",&choice);

		switch(choice){
			case 1: display(head);
					break;

			case 2:	scanf(" %c", &data);
					insert(head, data);
					break;

			case 3:	scanf(" %c", &data);
					head = delete(head, data);
					break;

			case 4:	scanf("%c", &data);
					//find_data(head, data);
					break;

			case 5:	exit(0);
		}
	}
	
}