#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node *next;
};

void printList(struct node *);
void push(struct node **, int);

int main() {
	struct node *node1, *node2, *node3;
	node1 = (struct node*)malloc(sizeof(struct node));
	node2 = (struct node*)malloc(sizeof(struct node));
	node3 = (struct node*)malloc(sizeof(struct node));

	printf("bir dugumun boyutu : %d\n\n", sizeof(struct node));

	printf("node1'in adresi : %d\n", node1);
	printf("node2'nin adresi : %d\n", node2);
	printf("node3'un adresi : %d\n", node3);

	node1->data = 15;
	node2->data = 20;
	node3->data = 25;

	node1->next = node2;
	node2->next = node3;
	node3->next = NULL;

	printf("\n");	
	printf("node1'in nextinin adresi = %d\n", node1->next);
	printf("node2'nin adresi = %d\n", node2);

	printf("\nbagli liste :\n");
	printList(node1);

	// basa ekleme
	push(&node1, 40);

	printf("\nbasa ekleme sonrasi:\n");
	printList(node1);

	// araya ekleme
	struct node *node4;
	node4 = (struct node*)malloc(sizeof(struct node));
	node4->data = 30;
	node4->next = node3;
	node2->next = node4;

	printf("\naraya ekleme sonrasi:\n");
	printList(node1);

	// sondan silme
	node4->next = NULL;
	free(node3);

	printf("\nsondan silme sonrasi:\n");
	printList(node1);

	printf("\nguncel liste:\n");
	printList(node1);

	return 0;
}

void printList(struct node* node) {
	int length = 0;
	while (node != NULL) {
		//node yerine node->next dedigimizde son dugumu gostermez
		length++;
		printf("%d\n", node->data);
		node = node->next;
	}
	printf("eleman sayisi = %d\n", length);
	length = 0;
}

void push(struct node** head, int data) {
	struct node *node = (struct node*)malloc(sizeof(struct node));
	node->data = data;
	node->next = (*head);
	(*head) = node;
}