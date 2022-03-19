#pragma warning (disable : 4996)
#include <stdio.h>
#include <stdlib.h>

#define false 0;
#define true 1;

typedef struct _pair_ {
	int first;
	int second;
}pair;


typedef struct _queue_{
	pair v;
	_queue_* next;
	void (*push_back)(pair);
	int (*empty)(void);
	void (*pop)(void);
	pair (*front)(void);
}queue; 


int N;
int* visited;
int* data;

queue* f;
queue* r;

void _push_back(pair v);
int _empty();
void _pop();
pair _front();
void _make_queue(pair v);

int calculate() {
	visited[0] = true;
	_make_queue(pair{ 0,0 });
	queue* q = f;


	while (!q->empty()) {
		pair front = q->front();

		if (front.first == N - 1) return front.second;

		for (int k = 0; k < data[front.first]; k++) {
			int nx = front.first + k;
			if (nx < N) {
				if (!visited[nx]) {
					visited[nx] = true;
					q->push_back(pair{nx, front.second + 1});
				}
			}
		}
	}
	return -1;
}

int main() {
	scanf("%d", &N);
	visited = (int*)calloc(N, sizeof(int));
	data = (int*)calloc(N, sizeof(int));
	for (int k = 0; k < N; k++) {
		scanf("%d", &data[k]);
	}

	printf("%d", calculate());
}

pair _front() {
	return f->v;
}

void _push_back(pair v) {
	//q가 비었으면
	if (_empty()) {
		(void)_make_queue(v);
	}
	else {
		queue* q = (queue*)malloc(sizeof(queue));
		q->v = v;
		q->push_back = _push_back;
		q->empty = _empty;
		q->pop = _pop;
		q->front = _front;
		r->next = q;
		r = q;
	}
	
}

int _empty() {
	if (f == NULL || r == NULL) return 1;
	else return 0;
}

void _pop() {
	queue* q = f;
	f = f->next;
	free(q);
}

void _make_queue(pair v) {
	f = r = (queue*)malloc(sizeof(queue));
	f->v = v;
	f->push_back = _push_back;
	f->empty = _empty;
	f->pop = _pop;
	f->front = _front;
	f->next = NULL;
}