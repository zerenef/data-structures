#include <stdio.h>
#include <stdlib.h>

struct node{
  int data;
  struct node *next;
};

void printList(struct node *);
void lengthOfList(struct node *);
int lengthOfListWithInt(struct node *);
void append(struct node **, int);
void addToEnd(struct node *, int);
void addToHead(struct node **, int);
void addAfterN(struct node *, int, int);
void addAfterGivenNumber(struct node *, int, int);
void addAfterGivenNode(struct node *, int);
void deleteEnd(struct node *);
void deleteHead(struct node **);
void deleteAfterN(struct node *, int);
int search(struct node *, int);
int searchRecursive(struct node *, int);
void deleteGivenNumber(struct node *, int);
void deleteGivenNode(struct node *, struct node *);
void reverse(struct node **);
void swap(int *, int *);
void swapNodes(struct node *, int, int);
void pairwiseSwap(struct node *);
void pairwiseSwapIterative(struct node *);
struct node *goForward(struct node *, int);

int main(){
  struct node *head = NULL;

  int arr[] = {1, 2, 3, 4, 5};
  int length = sizeof(arr) / sizeof(int);

  for (int i = 0; i < length; i++)
    append(&head, arr[i]);
  printf("liste ###\n");
  printList(head);

  printf("\nekleme sonrasi >>\n");
  addToEnd(head, 6);
  addToHead(&head, 0);
  addAfterN(head, 7, 7);
  addAfterGivenNumber(head, 8, 7);
  addAfterGivenNode(head->next->next->next, 143);
  printList(head);

  printf("\nsilme sonrasi <<\n");
  deleteEnd(head);
  deleteHead(&head);
  deleteAfterN(head, 3);
  deleteGivenNumber(head, 5);
  deleteGivenNode(head, goForward(head, 4));
  printList(head);

  printf("\nters cevirme sonrasi >|<\n");
  reverse(&head);
  printList(head);

  printf("\nyer degistirme sonrasi </>\n");
  swapNodes(head, 7, 2);
  printList(head);

  printf("\nikili yer degistirme sonrasi </>\n");
  pairwiseSwap(head);
  printList(head);

  return 0;
}

// yazdir
void printList(struct node *node){
  while (node != NULL){
    printf("%d\t", node->data);
    node = node->next;
  }
}

// bagli listenin uzunlugu - void
void lengthOfList(struct node *head){
  int lengthOfList = 1;
  while (head->next != NULL){
    head = head->next;
    lengthOfList++;
  }
  printf("listenin uzunlugu = %d\n", lengthOfList);
}

// bagli listenin uzunlugu - int
int lengthOfListWithInt(struct node *head){
  int lengthOfList = 1;
  while (head->next != NULL){
    head = head->next;
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
    (*head) = new_node;
    return;
  }
  while (last->next != NULL)
    last = last->next;
  last->next = new_node;
  return;
}

// sona ekle
void addToEnd(struct node *head, int x){
  struct node *new_node = (struct node *)malloc(sizeof(struct node));
  new_node->data = x;
  while (head->next != NULL)
    head = head->next;
  new_node->next = NULL;
  head->next = new_node;
}

// basa ekle
void addToHead(struct node **head, int x){
  struct node *new_head = (struct node *)malloc(sizeof(struct node));
  new_head->data = x;
  new_head->next = (*head);
  (*head) = new_head;
}

// n. dugumden sonra ekle
void addAfterN(struct node *node, int x, int n){
  int lengthOfList = lengthOfListWithInt(node);
  if (n<lengthOfList){
    printf("verdiginiz sira listede yok\n");
    return;
  }
  struct node *new_node = (struct node *)malloc(sizeof(struct node));
  new_node->data = x;
  for (int i = 1; i < n; i++)
    node = node->next;
  if (node->next == NULL){
    new_node->next = NULL;
    node->next = new_node;
    return;
  }
  new_node->next = node->next;
  node->next = new_node;
  return;
}

// verilen sayidan sonra ekle
void addAfterGivenNumber(struct node *node, int x, int number){
  if(!search(node, number)){
    printf("böyle bir sayi yok\n");
    return;
  }    
  struct node *new_node = (struct node *)malloc(sizeof(struct node));
  new_node->data = x;
  while (node->data != number)
    node = node->next;
  if (node->next == NULL){
    new_node->next = NULL;
    node->next = new_node;
    return;
  }
  new_node->next = node->next;
  node->next = new_node;
  return;
}

// verilen dugumden sonra ekle
void addAfterGivenNode(struct node *prev_node, int x){
  struct node *new_node = (struct node *)malloc(sizeof(struct node));
  new_node->data = x;
  new_node->next = prev_node->next;
  prev_node->next = new_node;
}

// sondan sil
void deleteEnd(struct node *head){
  while (head->next->next != NULL)
    head = head->next;
  struct node *temp = head->next;
  head->next = NULL;
  free(temp);
}

// bastan sil
void deleteHead(struct node **head){
  struct node *temp = (*head);
  (*head) = (*head)->next;
  free(temp);
}

// n. dugumden sonraki dugumu sil
void deleteAfterN(struct node *node, int n){
  int lengthOfList = lengthOfListWithInt(node);
  if (lengthOfList <= n){
    printf("verdiginiz sira listede yok\n");
    return;
  }
  for (int i = 1; i < n; i++)
    node = node->next;
  struct node *temp = node->next;
  node->next = node->next->next;
  free(temp);
}

// verilen sayi listede var mi
int search(struct node *head, int x){
  struct node *tmp = head;
  while (tmp != NULL){
    if (tmp->data == x)
      return 1;
    tmp = tmp->next;
  }
  return 0;
}

// verilen sayi listede var mi - recursive
int searchRecursive(struct node *head, int x){
  struct node *temp = head;
  if (temp == NULL)
    return 0;
  if (temp->data == x)
    return 1;
  return searchRecursive(temp->next, x);
}

// verilen sayinin dugumunu sil
void deleteGivenNumber(struct node *node, int number){
  if (!searchRecursive(node, number)){
    printf("boyle bir sayi yok\n");
    return;
  }
  while (node->next->data != number)
    node = node->next;
  struct node *temp = node->next;
  node->next = node->next->next;
  free(temp);
}

// verilen dugumu sil
void deleteGivenNode(struct node *head, struct node *node){
  while (head->next != NULL && head->next != node)
    head = head->next;
  struct node *temp = head->next;
  head->next = head->next->next;
  free(temp);
}

// ters cevir
void reverse(struct node ** head){
  struct node *prev = NULL, *next, *cur = (*head);
  while (cur != NULL){
    next = prev;
    prev = cur;
    cur = cur->next;
    prev->next = next;
  }
  (*head) = prev;
}

// pythonda yapilan a,b = b,a islemi gibi
// a degiskenindeki degeri b degiskenine, b degiskenindeki degeri a degiskenine at
void swap(int *a, int *b){
  int tmp = *a;
  *a = *b;
  *b = tmp;
}

// verilen iki sayinin yerini degistirme
void swapNodes(struct node *head, int x, int y){
  if (x==y) return;
  struct node *node1 = NULL, *node2 = NULL, *tmpX = head, *tmpY = head;
  
  while(search(tmpX, x)){
    node1 = tmpX;
    tmpX = tmpX->next;
  }

  while(searchRecursive(tmpY, y)){
    node2 = tmpY;
    tmpY = tmpY->next;
  }

  if(node1 == NULL){
    printf("verilen sayilardan ilki listede yok\n");
    return;
  } else if(node2 == NULL){
    printf("verilen sayilardan ikincisi listede yok\n");
    return;
  }
  swap(&node1->data, &node2->data);
}

// listedeki elemanlarin ikili ikili yerini degistirme - recursive
void pairwiseSwap(struct node * head){
  if(head != NULL && head->next != NULL){
    swap(&head->data, &head->next->data);
    pairwiseSwap(head->next->next);
  }
}

// listedeki elemanlarin ikili ikili yerini degistirme - iterative
void pairwiseSwapIterative(struct node * head){
  while (head != NULL && head->next != NULL){
    swap(&head->data, &head->next->data);
    head=head->next->next;
  }
}

// n. dugume gidip onu geri dondur
// sürekli head->next->next... islemi yapmamak icin yazilmis bir fonksiyon
struct node *goForward(struct node *head, int n){
  int lengthOfList = lengthOfListWithInt(head);
  if (n > lengthOfList){
    printf("verdiginiz sira listede yok\n");
    return head;
  }
  for (int i = 1; i < n; i++)
    head = head->next;
  return head;
}