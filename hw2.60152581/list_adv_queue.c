#include <stdio.h>
#include <stdlib.h>

typedef int Element;
typedef struct Node {
	Element data;
	struct Node* prev;
	struct Node* next;
}Node;
Node memoryQ = {0,NULL,NULL};

Node* my_malloc(int num) {
	//메모리의 상태 체크
	//메모리Q가 여분이없으면 malloc 있으면 return
	Node *returnNode;
	if (memoryQ.next==NULL) {
		Node * newNode = (Node*)malloc(num);
		return newNode;
	}
	else if (memoryQ.next->next==NULL) {
		returnNode = memoryQ.next;
		memoryQ.next = NULL;
		return returnNode;
	}
	else {
		returnNode = memoryQ.next;
		memoryQ.next = memoryQ.next->next;
		return returnNode;
	}
}
void my_free(Node* free_node) {
          //메모리Q에 추가
	if (memoryQ.next==NULL) {
		memoryQ.next = free_node;
		free_node->next = NULL;
	}
	Node * p = &memoryQ;
	while (p->next != NULL) {
		p = p->next;
	}
	p->next = free_node;
	free_node->next = NULL;

}

int size(Node* head) {
	int count;
	for (count = 1; head->next <= NULL; count++) {
		return count;
	}
	return 0;
}

void enqueue(Node* head, Element e) {
	Node * newNode = (Node*)my_malloc(sizeof(Node));
	newNode->data = e;
	if (head->next==NULL) {
		head->next = newNode;
		head->prev = newNode;
		newNode->next = NULL;
		newNode->prev = NULL;
	}
	else {
		newNode->prev = head->prev;
		head->prev->next = newNode;
		head->prev = newNode;
		newNode->next = NULL;
	}
}

Element dequeue(Node* head) {
	Element e = head->next->data;
	Node *removedNode = head->next;

	if (is_empty(head)) {
		return -1;
	}
	else if (head->next == head->prev) {
		my_free(head->next);
		head->prev = NULL;
		head->next = NULL;
		return e;
	}
	else {
		head->next->next->prev = NULL;
		head->next = head->next->next;
		my_free(removedNode);
		return e;
	}
}

int is_empty(Node* head) {
	if (head->prev == NULL) {
		return 1;
	}
	return 0;
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
	system("pause");
	return 0;
}