#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct node * pNode;
typedef pNode List;
typedef pNode Node;

struct node {
	int value;
	Node next;
};

void Showlist(List L) {
	List temp = L->next;
	for (;temp;temp = temp->next)
		printf("%d ", temp->value);
	printf("\n");
}

List makeEmptyList(List L) {
	L->next = NULL;
	return L;
}

void insert(int v, List L, Node N) {

	List temp = (List)malloc(sizeof(struct node));
	temp->value = v;
	temp->next = N->next;
	N->next = temp;
}

void deleteNode(int v, List L) {
	List trail = L;
	trail= NULL;
	while (L->next != NULL) {
		if (L->value == v) {
			break;
		}
		else {
			trail = L;
			L = L->next;
		}
	}
	if (trail == NULL)
		L = L->next;
	else
		trail->next = L->next;
	free(L);
	
}

Node findPrev(int v, List L) {
	List trail=L;
	while (trail->next != NULL) {
		if (trail->next->value == v) {
			return trail;
		}
		else {
			trail = trail->next;
		}
	}
		return NULL;
}

Node find(int v, List L) {
	Node temp = L->next;

	while (temp != NULL) {
		if (temp->value == v) {
			return temp;
		}
		temp = temp->next;
	}

	return NULL;
}

void deleteList(List L) {
	free(L);
	exit(1);
}

int main()
{
	Node L = (Node)malloc(sizeof(struct node));
	makeEmptyList(L);
	Node temp1=NULL;
	char *word;
	int num1, num2;
	char input[100];
	while (1) {
		int cnt = 1;
		gets(input);
		word = strtok(input, " ");
		if (strcmp(word, "i") == 0) {
			word = strtok(NULL, " ");
			num1 = atoi(word);

			word = strtok(NULL, " ");
			num2 = atoi(word);

			if (num2 == 0) {
				insert(num1, L, L);
				continue;
			}
			else
				temp1 = find(num2, L);
			if (temp1 == NULL) {
				printf("Insert error. The %d isn't in the list\n", num2);
				continue;
			}
			insert(num1, L, temp1);
		}
		else if (strcmp(word, "d")==0) {
			word = strtok(NULL, " ");
			num1 = atoi(word);
			temp1 = find(num1, L);
			if (temp1 == NULL) {
				printf("Delete error. The %d isn't in the list\n", num1);
				continue;
			}
			deleteNode(num1, L);
		}
		else if (strcmp(word, "f") == 0) {
			word = strtok(NULL, " ");
			num1 = atoi(word);
			temp1 = find(num1, L);
			if (temp1 == NULL) {
				printf("Find error. The %d isn't in the list\n", num1);
				continue;
			}
			Node b = findPrev(num1, L);
			num2 = b->value;
			if(b==L)
				printf("The %d is next of the header.\n", num1);
			else
				printf("The %d is next of the %d\n", num1,num2);

		}
		else if (strcmp(word, "s") == 0) {
			Showlist(L);
		}
		else if (strcmp(word, "e") == 0) {
			deleteList(L);
			cnt = 0;
		}
		if (cnt == 0)
			break;
	}
}