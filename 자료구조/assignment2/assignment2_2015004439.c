#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct stack *Stack;

struct stack {
	char *array;
	int size;
	int top;
};

Stack createStack(int arraySize) {
	Stack S = (Stack)malloc(sizeof(struct stack));

	S->size = arraySize;
	S->top = -1;
	S->array = (char*)malloc(sizeof(char)*arraySize);

	return S;
}
Stack makeEmptyStack(Stack S) {
	S->top = -1;
}
int IsEmpty(Stack S) {
	if (S->top == -1)
		return 1;
	else
		return 0;
}
int IsFull(Stack S) {
	if (S->top == (S->size) - 1)
		return 1;
	else
		return 0;
}
void push(char X, Stack S) {
	if (IsFull(S)) {
		printf("공간 부족\n");
		return;
	}
	S->array[++(S->top)] = X;
}
char pop(Stack S) {
	if (IsEmpty(S)) {
		printf("스택에 아무 것도 없음\n");
		return '\0';
	}
	return S->array[S->top--];
}
void deleteStack(Stack S) {
	free(S);
}
int main()
{
	Stack s;
	char X='\0';
	int exit = 1;
	char r[100];
	int cnt1=0;
	int cnt2 = 0;
	int check;
	int num;
	int arraySize=100;
	int l=0;
	int k;
	s= createStack(arraySize);
	while (1) {

		l = cnt1 = cnt2 = check = 0;
		for (num = 0;num < arraySize;num++) {
			scanf("%c", &X);
			if (X == ' ')
				continue;
			if (X == '#')
				break;
			if (X == '!') {
				exit = 0;
				break;
			}
			if (check) continue;
			if (X == '(' || (X >= 'a' && X <= 'z')) {
				push(X, s);
				if (X == '(')
					cnt1++;
			}
			else if (X == ')') {
				cnt2++;
				if (cnt1 - cnt2 < 0)
					check = 1;
				if (check) continue;
				while (!IsEmpty(s) && s->array[s->top] != '(')
					r[l++] = pop(s);
				pop(s);
			}
			if (cnt1-cnt2 == 0 && !IsEmpty(s)) r[l++] = pop(s);
		}
		if (exit == 0) {
			deleteStack(s);
			break;
		}
		if (cnt1 == cnt2)
			printf("right. ");
		else
			printf("wrong. ");
		for (k = 0;k < l;k++) {
			printf("%c ", r[k]);
		}
		s = makeEmptyStack(s);
		printf("\n");
	}
		
	
}