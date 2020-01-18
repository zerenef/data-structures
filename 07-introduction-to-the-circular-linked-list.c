#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node *next;
};

void printList(struct node*);
void convertCircular(struct node*);
void printCircular(struct node*);
struct node* addToEmpty(struct node*, int);
void insert(struct node*, int);

int main() {
	struct node *node1, *node2, *node3;
	node1 = (struct node*)malloc(sizeof(struct node));
	node2 = (struct node*)malloc(sizeof(struct node));
	node3 = (struct node*)malloc(sizeof(struct node));
	node1->data = 15;
	node2->data = 20;
	node3->data = 25;
	node1->next = node2;
	node2->next = node3;
	node3->next = NULL;

	printList(node1);

	convertCircular(node1);
	printCircular(node1);

	struct node *new_node = NULL;
	// atama yapmazsak new_node isimli pointer NULL oldugu icin hata verir
	new_node = addToEmpty(new_node, 180);
	printf("tek elemanli dairesel bagli liste = ");
	printCircular(new_node);

	insert(node2, 17);
	printCircular(node1);

	return 0;
}

// tek yonlu bagli listeyi yazdir
void printList(struct node* q) {
	int length = 0;
	while (q != NULL) {
		length++;
		printf("%d\n", q->data);
		q = q->next;
	}
	printf("eleman sayisi = %d\n\n", length);
	length = 0;
}

// tek yonlu bagli listeyi dairesel bagli listeye cevir
void convertCircular(struct node* head) {
	struct node* ptr = head;
	while (ptr->next != NULL)
		ptr = ptr->next;
	// sonuncu elemanin nexti bas olursa dairesel olur
	ptr->next = head;
}

// dairesel bagli listeyi yazdir
void printCircular(struct node* head) {
	struct node* ptr = head;
	do {
		printf("%d\n", ptr->data);
		ptr = ptr->next;
	} while (ptr != head);
	printf("\n");
}

// bagli liste bos ise yeni liste olusturup ekle
struct node* addToEmpty(struct node* node, int x) {
	if (node != NULL)
		return node;
	node = (struct node*)malloc(sizeof(struct node));
	node->data = x;
	node->next = node;
	// printf("tek elemanli dairesel bagli liste = %d\n", node->data);
	return node;
}

// verilen dugumden sonra ekle
void insert(struct node* head, int x) {
	struct node* newNode = (struct node*)malloc(sizeof(struct node));
	newNode->data = x;
	while (head->next == head)
		head = head->next;
	newNode->next = head->next;
	head->next = newNode;
}