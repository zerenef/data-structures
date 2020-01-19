#include <stdio.h>
#include <stdlib.h>

struct tree{
	int data;	struct tree *left;	struct tree *right;
};

struct tree *newNode(int data){
	struct tree *new = (struct tree*)malloc(sizeof(struct tree));
	new->data = data;
	new->left = new->right = NULL;
	return new;
}

//dugum sayisi
int size(struct tree *root){
	if (root == NULL) return 0;
	else return (size(root->left) + 1 + size(root->right));
}

//ikili arama agacinda ekleme
struct tree *insert(struct tree *root, int data) {
  if (root == NULL) return newNode(data);
  if (data < root->data)
    root->left = insert(root->left, data);
  else if (data > root->data)
    root->right = insert(root->right, data);
  return root;
}

//maximum derinlik
int maxDepth(struct tree *root){
	if (root == NULL) return 0;
	else {
		int leftDepth = maxDepth(root->left);
		int rightDepth = maxDepth(root->right);
		if(leftDepth > rightDepth) return (leftDepth + 1);
		else return (rightDepth + 1);
	}
}

//minimum deger
int minValue(struct tree *root){
	while (root->left != NULL)
		root = root->left;
	return root->data;
}

//ayna, simetri
void mirror(struct tree *root){
	if (root == NULL) return;
	else {
		struct tree *tmp;
		mirror(root->left);
		mirror(root->right);
		tmp = root->left;
		root->left = root->right;
		root->right = tmp;
	}
}

//agacin yuksekligi
int height(struct tree *root){
	int h = 0;
	while (root != NULL){
		h++; root = root->right;
	}
	return h;
}

void printTree(struct tree *root){
	if(root == NULL) return;
	printTree(root->left);
	printf("%d\n", root->data);
	printTree(root->right);
}

int main(){
	/* 
	olusturulacak agac
        7
      /   \
     4     11
    / \    / \
   3   6  9   12
      /
     5
	*/
	struct tree *root = newNode(7);
  /* 
	elle de agaci olusturabiliriz
  root = newNode(7);
  root->left = newNode(4);
	root->left->left = newNode(3);
  root->left->right = newNode(6);
  root->left->right->left = newNode(5);
  root->right = newNode(11);
  root->right->left = newNode(9);
	root->right->right = newNode(12);
  */

  insert(root, 4); insert(root, 11); insert(root, 9);
  insert(root, 6); insert(root, 12); insert(root, 5); insert(root, 3);

  printTree(root);

	printf("yukseklik = %d\n", height(root));
  printf("dugum sayisi = %d\n", size(root));
  printf("minimum deger = %d\n", minValue(root));
  printf("maksimum derinlik = %d\n", maxDepth(root));
  printf("sol = %d\n", root->left->data);
  mirror(root);
  printf("mirror fonksiyonundan sonra sol = %d\n", root->left->data);

	return 0;
}