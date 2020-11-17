#include <stdio.h>
#include <stdlib.h>


typedef int Element;
typedef struct Node {
	Element data;
	struct Node* link;

}Node;

Element pop(Node* head) {
	Node* removedNode = head->link;
	Element e = removedNode->data;
	head->link = head->link->link;
	free(removedNode);
	return e;
}

int size(Node* head){
	Node*p;
	int count = 0;
	for (p = head; p != NULL; p->link) {
		count++;
	}
	return count;

}

void push(Node* head, Element e) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = e;

	newNode->link = head->link;
	head->link = newNode;
}

int is_empty(Node* head) {
	if (head->link == NULL) {
		return 1;
	}
	else {
		return 0;
	}
}

int is_full(Node* head) {
	return 0;  //항상 실패
}

void print_stack(Node* head) {
	while (head->link != NULL) {
		head = head->link;
		printf("%d", head->data);
	}
	printf("\n");
}


int main() {
	Node stack = { 0, NULL }; // top 포인터는 stack->link
	push(&stack, 1); push(&stack, 2); push(&stack, 3); print_stack(&stack);
	pop(&stack); pop(&stack); pop(&stack); print_stack(&stack);
	push(&stack, 4); push(&stack, 5); push(&stack, 6); push(&stack, 7); print_stack(&stack); pop(&stack); pop(&stack); pop(&stack); print_stack(&stack);
	push(&stack, 8); push(&stack, 9); print_stack(&stack);
	pop(&stack); pop(&stack); pop(&stack); print_stack(&stack);
	return 0;

}