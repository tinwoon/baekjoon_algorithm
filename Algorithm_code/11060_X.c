#pragma warning (disable : 4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct pair {
	int first;
	int second;
}pair;

typedef struct Node {
	pair data;
	Node* next;
}Node;

typedef struct Queue {
	Node* front;
	Node* rear;
}Queue;

int N;
int* value;
int* visited;

void init(Queue* q) {
	q->front = q->rear = NULL;
	return;
}

int empty(Queue* q) {
	if(q->front == NULL || q->rear == NULL) return 1;
	return 0;
}

void emplace(Queue* q, pair data) {
	Node* node = (Node*)malloc(sizeof(Node));
	if (empty(q)) {
		q->front = node;
	}
	else {
		q->rear->next = node;
	}
	q->rear = node;
	q->rear->data = data;
	q->rear->next = NULL;
	return;
}

pair pop(Queue* q) {
	Node* node;
	pair data;

	if (empty(q)) {
		return pair{ -1,-1 };
	}
	node = q->front;
	data = node->data;
	q->front = node->next;
	free(node);
	node = NULL;

	return data;
}

int calculate() {

	Queue* q = (Queue*)malloc(sizeof(Queue));
	init(q);
	visited[0] = 1;
	emplace(q, pair{ 0,0 });

	while (!empty(q)) {
		int front = q->front->data.first;
		int ans = q->front->data.second;
		(void)pop(q);

		if (front == N - 1) return ans;

		for (int k = 1; k <= value[front]; k++) {
			int nx = front + k;

			if (nx < N) {
				if (!visited[nx]) {
					visited[nx] = 1;
					emplace(q, pair{nx, ans + 1});
				}
			}
		}
	}

	return -1;
}



int main() {
	scanf("%d", &N);
	value = (int*)malloc(sizeof(int) * N);
	visited = (int*)calloc(N, sizeof(int));
	for (int k = 0; k < N; k++) {
		scanf("%d", &value[k]);
	}
	printf("%d", calculate());
}