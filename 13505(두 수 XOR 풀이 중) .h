#pragma warning (disable : 4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _Tree_ {
	_Tree_* left = NULL;
	_Tree_* right = NULL;
}Tree;

int compare(const void* a, const void* b) {
	int A = *(int*)a;
	int B = *(int*)b;
	if (a < b) return true;
	else return false;
}

int N;
Tree*  root;
int* data;
//최대 상위 비트가 몇까지 같은지 알려준다.
//해당 비트가 같은게 없다면 그 다음 비트로 이동하는게 방법이다.
int bit_level;

int find_high_bit(int v) {
	for (int k = 15; k >= 0; k--) {
		if (v >= (1 << k)) return k;
	}
	return -1;
}

int node_empty(Tree* node) {
	if (node == NULL) return 1;
	else return 0;
}

void make_tree() {
	for (int i = 0; i < N; i++) {
		Tree* pnode = root;
		for (int j = bit_level; j >= 0; j--) {
			if (data[i] & (1 << j)) {
				//만약 넣으려하는데 노드가 없으면 노드 생성하기
				if (node_empty(pnode->left)) {
					Tree* node = (Tree*)malloc(sizeof(Tree));
					pnode->left = node;
					pnode = pnode->left;
				}
				else {
					pnode = pnode->left;
				}
			}
			else {
				//만약 넣으려하는데 노드가 없으면 노드 생성하기
				if (node_empty(pnode->right)) {
					Tree* node = (Tree*)malloc(sizeof(Tree));
					pnode->right = node;
					pnode = pnode->right;
				}
				else {
					pnode = pnode->right;
				}
			}
		}
	}
}

void calculate() {
	int high_bit;
	int b_l = bit_level;
	for (int k = 0; k < N; k++) {
		if (data[k] & (1 << (b_l--))) {
			Tree* pnode = root->left;
			
		}
		else break;
	}
}

int main() {
	scanf("%d", &N);
	root = (Tree*)malloc(sizeof(Tree));
	data = (int*)malloc(sizeof(int) * N);

	for (int k = 0; k < N; k++) {
		scanf("%d", &data[k]);
	}
	//내림차순으로 정렬
	qsort(data, N, sizeof(int), compare);
	//제일 큰 값에서 가장 높은 비트의 자리수(bit_level)을 넣는다.
	bit_level = find_high_bit(data[0]);
	//tree를 만든다. left가 있는 경우는 상위 비트부터 시작해서 1에 해당하는 내역이다.
	//right가 있는 경우는 상위 비트부터 시작해서 0에 해당하는 내역이다.
	make_tree();
	
}