#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node *next;
};

void printList(struct node *);
void insertAfter(struct node *, int);
void push(struct node **, int);
void insert(struct node *, int);
void del(struct node *, int);
void reverse(struct node **);
void delToHead(struct node **);

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

	insertAfter(node2,30);
	printList(node1);

	push(&node1, 10);
	printList(node1);

	insert(node1, 22);
	printList(node1);

	del(node1, 20);
	printList(node1);

	reverse(&node1);
	printList(node1);

	delToHead(&node1);
	printList(node1);

	return 0;
}

// bagli listeyi yazdir
void printList(struct node *q) {
	int length = 0;
	while (q != NULL) {
		length++;
		printf("%d\n", q->data);
		q = q->next;
	}
	printf("eleman sayisi = %d\n\n", length);
	length = 0;
}

// verilen dugumden sonra ekle
void insertAfter(struct node* prev_node, int x) {
	if (prev_node == NULL)
		return;
	struct node* node = (struct node*)malloc(sizeof(struct node));
	node->data = x;
	node->next = prev_node->next;
	prev_node->next = node;
}

// basa ekle
void push(struct node** head, int x) {
	struct node* node = (struct node*)malloc(sizeof(struct node));
	node->data = x;
	node->next = (*head);
	(*head) = node;
}

// while dongusunde verilen sarta gore araya ekle
void insert(struct node* ptr, int x) {
	struct node* node = (struct node*)malloc(sizeof(struct node));
	node->data = x;
	while (ptr->data != 20)
		ptr = ptr->next;
	node->next = ptr->next;
	ptr->next = node;
}

// verilen veriyi silme
void del(struct node* ptr, int x) {
	while (ptr->next->data != x)
		ptr = ptr->next;
	struct node* deleted = ptr->next;
	ptr->next = ptr->next->next;
	free(deleted);
}

// ters cevir
void reverse(struct node** x) {
	struct node *q=NULL, *r=NULL, *s;
	q = *x;
	while (q != NULL) {
		s = r;
		r = q;
		q = q->next;
		r->next = s;
	}
	*x = r;
}

// bastan silme
void delToHead(struct node** head) {
	struct node* deleted = *head;
	*head = (*head)->next;
	free(deleted);
}