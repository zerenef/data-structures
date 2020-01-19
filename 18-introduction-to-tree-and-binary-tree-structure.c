#include <stdio.h>
#include <stdlib.h>

struct tree{
	int data;
	struct tree *left;
	struct tree *right;
};

struct tree *newNode(int data){
	struct tree *new = (struct tree*)malloc(sizeof(struct tree));
	new->data = data;
	new->left = new->right = NULL;
	return new;
}

void inOrder(struct tree *root){
	if(root == NULL) return;
	inOrder(root->left);
	printf("%d ", root->data);
	inOrder(root->right);
}

void preOrder(struct tree *root){
	if(root == NULL) return;
	printf("%d ", root->data);
	preOrder(root->left);
	preOrder(root->right);
}

void postOrder(struct tree *root){
	if(root == NULL) return;
	postOrder(root->left);
	postOrder(root->right);
	printf("%d ", root->data);
}

//agacin yuksekligi
int height(struct tree *q){
	int h = 0;
	while(q != NULL){
		h++;
		q = q->right;
	}
	return h;
}

int main(){
	struct tree *root = newNode(5);
	root->right = newNode(8);
	root->left = newNode(4);
	root->left->left = newNode(2);
	root->right->right = newNode(15);

	printf("sagin sagi = %d\n", root->right->right->data);
	printf("yukseklik = %d\n", height(root));

	printf("PreOrder  : "); preOrder(root); printf("\n");
	printf("InOrder	  : "); inOrder(root); printf("\n");
	printf("PostOrder : "); postOrder(root); printf("\n");

	return 0;
}