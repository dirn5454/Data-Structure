#include <stdio.h>
#include <stdlib.h>

typedef int Element;
typedef struct Node {
	Element data;
	struct Node* prev;
	struct Node* next;
}Node;

int size(Node* head) {
	int count = 0;
	if (head->next != NULL) {
		count++;
	}
	return count;
}

void enqueue(Node* head, Element e) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = e;
	if (is_empty(head)){
		head->next = newNode;
		head->prev = newNode;
		newNode->next = NULL;
		newNode->prev = NULL;
	}
	else {
		head->prev->next = newNode;
		newNode->prev = head->prev;
		head->prev = newNode;
		newNode->next = NULL;
	}
	
}

Element dequeue(Node* head) {
	Node* removedNode = head->next;
	Element e = removedNode->data;
	if (is_empty(head)) {
		return 0;
	}
	else if (head->next == head->prev) {
		head->next = NULL;
		head->prev = NULL;
		free(removedNode);
		return e;
	}
	else {
		removedNode->next->prev = NULL;
		head->next = removedNode->next;
		free(removedNode);
		return e;
	}

}

int is_empty(Node* head) {
	if (head->prev == NULL) {
		return 1;
	}
	else {
		return 0;
	}
	
}

int is_full(Node*head) { return 0; } // 항상 실패

void print_queue_front_to_back(Node* head) {
	Node* front = head->next;
	while (front != NULL) {
		printf(" %d ", front->data);
		front = front->next;
	}
	printf("\n");
}

void print_queue_back_to_front(Node* head) {
	Node* rear = head->prev;
	while (rear != NULL) {
		printf(" %d ", rear->data);
		rear = rear->prev;
	}
	printf("\n");
}

void print_queue(Node* head) {
	print_queue_front_to_back(head);
	print_queue_back_to_front(head);
}

int main() {
	Node queue = { 0, NULL, NULL }; // queue.next : front, queue.prev : rear 포인터 
	int i, j;
	for (i = 0; i < 3; ++i) enqueue(&queue, i);
	print_queue(&queue);
    for (j = 0; j < 3; ++j) dequeue(&queue);
	print_queue(&queue);
	for (; i < 8; ++i) enqueue(&queue, i);
	print_queue(&queue);
	for (j = 0; j < 3; ++j) dequeue(&queue);
	print_queue(&queue);
	for (; i < 10; ++i) enqueue(&queue, i);
	print_queue(&queue);
	return 0;
}