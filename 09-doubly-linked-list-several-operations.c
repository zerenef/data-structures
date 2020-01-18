#include <stdio.h>
#include <stdlib.h>

struct node{
  int data;
  struct node *next;
  struct node *prev;
};

void printList(struct node *);
void lengthOfList(struct node *);
int lengthOfListWithInt(struct node *);
void append(struct node **, int);
void addToTheEnd(struct node *, int);
void addToTheHead(struct node **, int);
void addAfterN(struct node *, int, int);
void addAfterGivenNumber(struct node *, int, int);
void addAfterGivenNode(struct node *, int);
void deleteFromTheEnd(struct node *);
void deleteAHeadNode(struct node **);
void deleteAfterN(struct node *, int);
int search(struct node *, int);
int searchRecursive(struct node *, int);
void deleteGivenNumber(struct node *, int);
void deleteGivenNode(struct node *, struct node *);
void reverse(struct node **);

int main(){
  struct node *head = NULL;

  int arr[] = {1, 2, 3};
  int length = sizeof(arr) / sizeof(int);

  for (int i = 0; i < length; i++)
    append(&head, arr[i]);
  printf("liste\n");
  printList(head);

  printf("\nekleme sonrasi\n");
  addToTheEnd(head, 4);
  addToTheHead(&head, 0);
  addAfterN(head, 20, 2);
  addAfterGivenNumber(head, 22, 20);
  addAfterGivenNode(head->next->next, 77);
  printList(head);

  
  printf("\nsilme sonrasi\n");
  deleteFromTheEnd(head);
  deleteAHeadNode(&head);
  deleteAfterN(head, 3);
  deleteGivenNumber(head, 77);
  deleteGivenNode(head, head->next);
  printList(head);

  printf("\nters cevirme sonrasi\n");
  reverse(&head);
  printList(head);

  return 0;
}

// yazdir
void printList(struct node *node){
  while (node != NULL){
    printf("%d\n", node->data);
    node = node->next;
  }
}

// bagli listenin uzunlugu - void
void lengthOfList(struct node *node){
  int lengthOfList = 1;
  while (node->next != NULL){
    node = node->next;
    lengthOfList++;
  }
  printf("listenin uzunlugu = %d\n", lengthOfList);
}

// bagli listenin uzunlugu - int
int lengthOfListWithInt(struct node *node){
  int lengthOfList = 1;
  while (node->next != NULL){
    node = node->next;
    lengthOfList++;
  }
  return lengthOfList;
}

// bos ise yeni bir bagli olustur degilse sonuna ekle
void append(struct node **head, int data){
  struct node *new_node = (struct node *)malloc(sizeof(struct node));
  struct node *last = (*head);
  new_node->data = data;
  new_node->next = NULL;
  if ((*head) == NULL){
    new_node->prev = NULL;
    (*head) = new_node;
    return;
  }
  while (last->next != NULL)
    last = last->next;
  last->next = new_node;
  new_node->prev = last;
  return;
}

// sona ekle
void addToTheEnd(struct node *node, int x){
  struct node *new_node = (struct node *)malloc(sizeof(struct node));
  new_node->data = x;
  new_node->next = NULL;
  while (node->next != NULL)
    node = node->next;
  node->next = new_node;
  new_node->prev = node;
}

// basa ekle
void addToTheHead(struct node **head, int x){
  struct node *new_head = (struct node *)malloc(sizeof(struct node));
  new_head->data = x;
  new_head->prev = NULL;
  new_head->next = (*head);
  (*head)->prev = new_head;
  (*head) = new_head;
}

// n. dugumden sonra ekle
void addAfterN(struct node *node, int x, int n){
  struct node *new_node = (struct node *)malloc(sizeof(struct node));
  new_node->data = x;
  for (int i = 1; i < n; i++)
    node = node->next;
  if (node->next == NULL){
    node->next = new_node;
    new_node->next = NULL;
    new_node->prev = node;
    return;
  }
  new_node->next = node->next;
  new_node->prev = node;
  node->next->prev = new_node;
  node->next = new_node;
  return;
}

// verilen sayidan sonra ekle
void addAfterGivenNumber(struct node *node, int x, int number){
  struct node *new_node = (struct node *)malloc(sizeof(struct node));
  new_node->data = x;
  while (node->data != number)
    node = node->next;
  if (node->next == NULL){
    new_node->next = NULL;
    node->next = new_node;
    new_node->prev = node;
    return;
  }
  new_node->next = node->next;
  new_node->prev = node;
  node->next->prev = new_node;
  node->next = new_node;
  return;
}

// verilen dugumden sonra ekle
void addAfterGivenNode(struct node *prev_node, int x){
  struct node *new_node = (struct node *)malloc(sizeof(struct node));
  new_node->data = x;
  new_node->next = prev_node->next;
  new_node->prev = prev_node;
  prev_node->next->prev = new_node;
  prev_node->next = new_node;
}

// sondan sil
void deleteFromTheEnd(struct node *head){
  while (head->next->next != NULL)
    head = head->next;
  struct node *temp = head->next;
  head->next->prev = head->next = NULL;
  free(temp);
}

// bastan sil
void deleteAHeadNode(struct node **head){
  struct node *temp = (*head);
  (*head) = (*head)->next;
  (*head)->prev->next = (*head)->prev = NULL;
  free(temp);
}

// n. dugumden sonraki dugumu sil
void deleteAfterN(struct node *node, int n){
  int lengthOfList = lengthOfListWithInt(node);
  if (lengthOfList <= n){
    printf("listenin uzunlugundan buyuk veya esit bir deger girdiniz!\n");
    return;
  }
  for (int i = 1; i < n; i++)
    node = node->next;
  struct node *temp = node->next;
  node->next = node->next->next;
  node->next->prev = node;
  free(temp);
}

// verilen sayi listede var mi
int search(struct node *node, int num){
  while (node != NULL){
    if (node->data == num)
      return 1;
    node = node->next;
  }
  return 0;
}

// verilen sayi listede var mi - recursive
int searchRecursive(struct node *node, int num){
  if (node == NULL)
    return 0;
  if (node->data == num)
    return 1;
  return searchRecursive(node->next, num);
}

// verilen sayinin dugumunu sil
void deleteGivenNumber(struct node *node, int num){
  if (!searchRecursive(node, num)){
    printf("boyle bir sayi yok!\n");
    return;
  }
  while (node->next->data != num)
    node = node->next;
  struct node *temp = node->next;
  node->next = node->next->next;
  node->next->prev = node;
  free(temp);
}

// verilen dugumu sil
void deleteGivenNode(struct node *head, struct node *node){
  while (head->next != NULL && head->next != node)
    head = head->next;
  struct node *temp = head->next;
  head->next = head->next->next;
  head->next->prev = head;
  free(temp);
}

// ters cevir
void reverse(struct node **head){
  struct node *p = NULL;
  struct node *c = (*head);
  struct node *n = NULL;
  while (c != NULL){
    n = c->next;
    c->next = p;
    p = c;
    c = n;
  }
  (*head) = p;
}