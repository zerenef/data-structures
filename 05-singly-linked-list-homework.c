/*
elimizde tek yonlu bir bagli liste var: ornegin; 5 6 1 1 10 30 30 45 84 100 100 84
ayni eleman varsa bunlari bulacak, elemanlarin arka arkaya olmasi gerekiyor
ornegin 5 6 1 2 6 1 olmaz
ayni olan elemanlari sayacak ve bu eleman ciftlerinin sayisinin asal olup olmadigini yazacak
yukaridaki ornekte 3 cift var (1 1 30 30 ve 100 100), 3 asal mi? evet
*/

#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node *next;
};

void printList(struct node *);
int isPrime(int);
void append(struct node **, int);

int main() {
	struct node *head = NULL;
	int arr[] = { 5,6,1,1,10,30,30,45,84,100,100,84 };
	int length = sizeof(arr) / sizeof(int);    // dizinin uzunlugu

	for (int i = 0; i < length; i++)
		append(&head, arr[i]);
	printList(head);

	int counter = 0;
	struct node *ptr1, *ptr2;
	ptr1 = head;
	ptr2 = head->next;
	while (ptr2 != NULL) {
		if (ptr1->data==ptr2->data)
			counter++;
		ptr1 = ptr1->next;
		ptr2 = ptr2->next;
	}
	
	printf("ardisik eleman sayisi : %d\n", counter);
	printf("%s\n", isPrime(counter) ? "asal" : "asal degil");

	return 0;
}

// yazdir
void printList(struct node *node) {
	while (node != NULL) {
		printf("%d\n", node->data);
		node = node->next;
	}
}

// asal mi?
int isPrime(int number) {
	int counter = 0;
	for (int i = 2; i < number; i++)
		if (number % i == 0)
			counter++;
	if (number == 1)
		return 0;
	else if (counter == 0)
		return 1;
	else
		return 0;
}

// bagli listeye eleman ekle
void append(struct node** head, int data){
	struct node* node = (struct node*)malloc(sizeof(struct node));
  struct node* last = (*head);
	node->data=data;
	node->next=NULL;
    if ((*head)==NULL){
        (*head)=node;
        return;
    }
    while(last->next!=NULL)
        last=last->next;
    last->next=node;
    return;
}