#include <stdio.h>
#include <stdlib.h>

typedef struct node node;
typedef node* Node;
typedef node* Tree;

struct node {
	int value;
	Node parent;
	Node leftChild;
	Node rightChild;
};

Tree createTree();
int isEmpty(Tree T);
Node search(Tree T, int key);
void deleteNode(Tree T, int key);
void insertNode(Tree T, int key);

void showAll(Tree T);
int getHeight(Tree T, int key);


int main() {

	Tree T = NULL;

	while (1) {
		char word;
		int key;
		scanf(" %c", &word);

		if (word == 'i') {
			scanf("%d", &key);

			if (isEmpty(T)) {
				T = createTree();
				insertNode(T, key);
			}
			else {
				insertNode(T, key);
			}
		}
		else if (word == 'd') {
			scanf("%d", &key);
			if (search(T, key) == NULL) {
				printf("Not found\n");
			}
			else {
				deleteNode(T, key);
			}
		}
		else if (word == 'h') {
			scanf("%d", &key);

			if (search(T, key) == NULL) {
				printf("Not found\n");
			}
			else {
				printf("The height of the node (%d) is %d\n", key, getHeight(search(T, key), key));
			}
		}
		else if (word == 's') {
			showAll(T);
			printf("\n");
		}
		else if (word == 'e') {
			break;
		}
	}
}

Tree createTree() {
	Node tmp;
	tmp = (Tree)malloc(sizeof(node));
	tmp->value = 0;
	tmp->parent = NULL;
	tmp->leftChild = NULL;
	tmp->rightChild = NULL;

	return tmp;
}
int isEmpty(Tree T) {
	if (T == NULL) return 1;
	return 0;
}
Node search(Tree T, int key) {
	if (T == NULL) return NULL;
	if (T->value == key) return T;
	else if (T->value < key) return search(T->rightChild, key);
	else if (T->value > key) return search(T->leftChild, key);
}
void deleteNode(Tree T, int key) {
	Node del, par, tmp, tmp2;
	int value;
	del = search(T, key);
	par = del->parent;

	if (del == par->leftChild) {
		if (del->leftChild == NULL && del->rightChild == NULL) {
			par->leftChild = NULL;
			free(del);
		}
		else if (del->leftChild != NULL && del->rightChild == NULL) {
			par->leftChild = del->leftChild;
			del->leftChild->parent = par;
			free(del);
		}
		else if (del->leftChild == NULL && del->rightChild != NULL) {
			par->leftChild = del->rightChild;
			del->rightChild->parent = par;
			free(del);
		}
		else if (del->leftChild != NULL && del->rightChild != NULL) {
			tmp = del->leftChild;
			value = tmp->value;

			while (tmp->rightChild != NULL) {
				tmp = tmp->rightChild;
				value = tmp->value;
			}

			deleteNode(tmp, value);
			del->value = value;
		}
	}
	else if (del == par->rightChild) {
		if (del->leftChild == NULL && del->rightChild == NULL) {
			par->rightChild = NULL;
			free(del);
		}
		else if (del->leftChild != NULL && del->rightChild == NULL) {
			par->rightChild = del->leftChild;
			del->leftChild->parent = par;
			free(del);
		}
		else if (del->leftChild == NULL && del->rightChild != NULL) {
			par->rightChild = del->rightChild;
			del->rightChild->parent = par;
			free(del);
		}
		else if (del->leftChild != NULL && del->rightChild != NULL) {
			tmp = del->leftChild;
			value = tmp->value;

			while (tmp->rightChild != NULL) {
				tmp = tmp->rightChild;
				value = tmp->value;
			}

			deleteNode(tmp, value);
			del->value = value;
		}
	}
}
void insertNode(Tree T, int key) {

	Node tmp;

	if (T->value < key) {
		if (T->rightChild != NULL) {
			insertNode(T->rightChild, key);
		}
		else {
			tmp = createTree();
			tmp->value = key;
			tmp->parent = T;
			T->rightChild = tmp;
		}
	}
	else if (T->value > key) {
		if (T->leftChild != NULL) {
			insertNode(T->leftChild, key);
		}
		else {
			tmp = createTree();
			tmp->value = key;
			tmp->parent = T;
			T->leftChild = tmp;
		}
	}
}

void showAll(Tree T) {
	if (T == NULL) return;
	showAll(T->leftChild);
	if (T->value != 0) {
		printf("%d ", T->value);
	}
	showAll(T->rightChild);
}
int getHeight(Tree T, int key) {

	int left = 0, right = 0;

	if (T->leftChild == NULL && T->rightChild == NULL) return 0;

	if (T->leftChild != NULL) {
		left = getHeight(T->leftChild, key);
	}
	if (T->rightChild != NULL) {
		right = getHeight(T->rightChild, key);
	}

	if (left > right) return left + 1;
	else return right + 1;
}