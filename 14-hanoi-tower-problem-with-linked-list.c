#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>

struct stack{
  unsigned capacity;
  int top;
  int *array;
};

struct stack *createStack(unsigned capacity){
  struct stack *stack = (struct stack *)malloc(sizeof(struct stack));
  stack->capacity = capacity;
  stack->top = -1;
  stack->array = (int *)malloc(sizeof(int) * stack->capacity);
  return stack;
}

int isFull(struct stack* stack){
  return (stack->top == stack->capacity - 1);
}  
  
int isEmpty(struct stack* stack){
  return (stack->top == -1);
}  

void push(struct stack *s, int data){
  if(isFull(s)) return;
  s->array[++s->top] = data;
}

int pop(struct stack *s){
  if(isEmpty(s)) return INT_MIN;
  return s->array[s->top--];
}

void moveDisk(char x, char y, int disk){
  printf("Hareket disk %d den \'%c\' arasinda \'%c\' \n", disk, x, y);
}

//moveDiskBetweenTwoPoles
void mDBTP(struct stack *s1, struct stack *s2, char s, char d){
  int pole1TopDisk = pop(s1);
  int pole2TopDisk = pop(s2);
  if (pole1TopDisk == INT_MIN){
    push(s1, pole2TopDisk);
    moveDisk(d, s, pole2TopDisk);
  }
  else if (pole2TopDisk == INT_MIN){
    push(s2, pole1TopDisk);
    moveDisk(s, d, pole1TopDisk);
  }
  else if (pole1TopDisk > pole2TopDisk){
    push(s1, pole1TopDisk);
    push(s1, pole2TopDisk);
    moveDisk(d, s, pole2TopDisk);
  }
  else{
    push(s2, pole2TopDisk);
    push(s2, pole1TopDisk);
    moveDisk(s, d, pole1TopDisk);
  }
}

void tohIterative(int count, struct stack *src, struct stack *aux, struct stack *dest){
  int i;
  char s = 'S', d = 'D', a = 'A';
  if (count % 2 == 0){
    char temp = d;
    d = a;
    a = temp;
  }

  int total_num_of_moves = pow(2, count) - 1;
  for (i = count; i >= 1; i--)
    push(src, i);
  for (i = 1; i <= total_num_of_moves; i++){
    if (i % 3 == 1)
      mDBTP(src, dest, s, d);
    else if (i % 3 == 2)
      mDBTP(src, aux, s, a);
    else if (i % 3 == 0)
      mDBTP(aux, dest, a, d);
  }
}

int main(){
  unsigned number_of_disks = 3;
  struct stack *src, *dest, *aux;
  src = createStack(number_of_disks);
  dest = createStack(number_of_disks);
  aux = createStack(number_of_disks);
  tohIterative(number_of_disks, src, aux, dest);
  return 0;
}