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
//�ִ� ���� ��Ʈ�� ����� ������ �˷��ش�.
//�ش� ��Ʈ�� ������ ���ٸ� �� ���� ��Ʈ�� �̵��ϴ°� ����̴�.
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
				//���� �������ϴµ� ��尡 ������ ��� �����ϱ�
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
				//���� �������ϴµ� ��尡 ������ ��� �����ϱ�
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
	//������������ ����
	qsort(data, N, sizeof(int), compare);
	//���� ū ������ ���� ���� ��Ʈ�� �ڸ���(bit_level)�� �ִ´�.
	bit_level = find_high_bit(data[0]);
	//tree�� �����. left�� �ִ� ���� ���� ��Ʈ���� �����ؼ� 1�� �ش��ϴ� �����̴�.
	//right�� �ִ� ���� ���� ��Ʈ���� �����ؼ� 0�� �ش��ϴ� �����̴�.
	make_tree();
	
}