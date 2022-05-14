#pragma warning (disable : 4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//18258 큐 2 문제
//전형적으로 큐를 만드는 문제
//다만 pop_back 당시에 head가 빌 시 tail도 같이 NULL로 해줘야하는 점을 기억할 것

typedef struct pair {
	int value;
}pair;

typedef struct Node {
	pair p;
	struct Node* next;
}Node;

typedef struct Queue {
	struct Node* head;
	struct Node* tail;
	int size;
}Queue;

void init(Queue* q) {
	q->head = q->tail = NULL;
	q->size = 0;
	return;
}

int empty(Queue* q) {
	if (q->head == NULL || q->tail == NULL) return 1;
	return 0;
}

void push_back(Queue* q, pair data) {
	Node* node = (Node*)malloc(sizeof(Node));

	if (empty(q)) {
		q->head = node;
	}
	else {
		q->tail->next = node;
	}
	node->p = data;
	q->tail = node;
	q->tail->next = NULL;
	q->size++;
	return;
}

pair pop(Queue* q) {
	Node* node;
	pair data;

	if (empty(q)) {
		data.value = -1;
		return data;
	}
	node = q->head;
	data = node->p;
	q->head = node->next;
	free(node);
	node = NULL;
	if (q->head == NULL) q->tail = NULL;
	q->size--;
	return data;
}

pair front(Queue* q) {
	pair pa = { -1 };
	return (q->head != NULL) ? q->head->p : pa;
}

pair back(Queue* q) {
	pair pa = { -1 };
	return (q->tail != NULL) ? q->tail->p : pa;
}

int size(Queue* q) {
	return q->size;
}

int N;
char cmd[100];
Queue* q;

void calculate() {

	if (!strcmp(cmd, "push")) {
		pair pa;
		scanf("%d", &pa.value);
		push_back(q, pa);
	}
	else if(!strcmp(cmd, "pop")){
		printf("%d\n", pop(q).value);
	}
	else if (!strcmp(cmd, "size")) {
		printf("%d\n", size(q));
	}
	else if (!strcmp(cmd, "empty")) {
		printf("%d\n", empty(q));
	}
	else if (!strcmp(cmd, "front")) {
		printf("%d\n", front(q).value);
	}
	else if (!strcmp(cmd, "back")) {
		printf("%d\n", back(q).value);
	}

	return;
}

int main() {
	scanf("%d", &N);
	q = (Queue*)malloc(sizeof(Queue));
	init(q);

	for (int k = 0; k < N; k++) {
		memset(cmd, 0, sizeof(char)*100);
		scanf("%s", cmd);
		calculate();
	}
	free(q);
	q = NULL;
}