#pragma warning (disable : 4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

typedef struct _Tree_ {
	_Tree_* left;
	_Tree_* right;
}Tree;

int N;
Tree* root;
int* data;
//�ִ� ���� ��Ʈ�� ����� ������ �˷��ش�.
//�ش� ��Ʈ�� ������ ���ٸ� �� ���� ��Ʈ�� �̵��ϴ°� ����̴�.
int bit_level;

int cmp(const void* a, const void* b) {
	int A = *(int*)a;
	int B = *(int*)b;
	if (A < B) return 1;
	else if (A > B) return -1;
	else return 0;
}

int find_high_bit(int v) {
	for (int k = 15; k >= 0; k--) {
		if (v >= (1 << k)) return k;
	}
	return -1;
}

int node_empty(Tree* node) {
	if (node == nullptr) return 1;
	else return 0;
}

Tree* init_node() {
	Tree* node = (Tree*)malloc(sizeof(Tree));
	node->right = node->left = nullptr;
	return node;
}

void make_tree() {
	root = init_node();
	for (int i = 0; i < N; i++) {
		Tree* pnode = root;
		for (int j = bit_level; j >= 0; j--) {
			if (data[i] & (1 << j)) {
				//���� �������ϴµ� ��尡 ������ ��� �����ϱ�
				if (node_empty(pnode->left)) {
					Tree* node = init_node();
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
					Tree* node = init_node();
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

int calculate() {
	int ans = 0;
	int high_bit = bit_level;
	int b_l;
	for (int k = 0; k < N; k++) {
		b_l = high_bit;
		//bit �ֽ�ȭ�� �߻��ߴ°�?
		int bit_change_flag = 0;
		//������� data[k]�� ���� �� �� ���� xor�� ũ�� ���� �� �ִ� ��.
		int present_value = 0;
		Tree* pnode = root;
		if (data[k] & (1 << (b_l--))) {
			//������ ��Ʈ�� ������
			if (pnode->right == nullptr) {
				pnode = pnode->left;
				high_bit = b_l;
				bit_change_flag = 1;
			}
			//���� ��Ʈ Ȯ��
			else {
				pnode = pnode->right;
				present_value += (1 << (b_l + 1));
			}

			while (b_l >= 0) {
				//data[k]�� b_l��Ʈ�� 1�϶�
				if (data[k] & (1 << (b_l--))) {
					//���� ��Ʈ�� 0�� ���� �ִٸ�
					if (pnode->right != nullptr) {
						pnode = pnode->right;
						present_value += (1 << (b_l + 1));
					}
					//���� ��Ʈ�� 0�� ���� ���ٸ�
					else {
						pnode = pnode->left;
						if (!bit_change_flag) {
							high_bit = b_l;
							//��Ʈ�� �ٲ����� ��ǥ
							bit_change_flag = 1;
						}
					}
				}
				//data[k]�� b_l��Ʈ�� 0�϶�
				else {
					//���� ��Ʈ�� 0�� ���� �ִٸ�
					if (pnode->left != nullptr) pnode = pnode->left;
					//���� ��Ʈ�� 0�� ���� ���ٸ�
					else {
						pnode = pnode->right;
						present_value += (1 << (b_l + 1));
						if (!bit_change_flag) {
							high_bit = b_l;
							//��Ʈ�� �ٲ����� ��ǥ
							bit_change_flag = 1;
						}
					}
				}
			}

			ans = ((data[k] ^ present_value) > ans) ? (data[k] ^ present_value) : ans;
		}
		else break;
	}

	return ans;
}

int main() {
	scanf("%d", &N);
	root = (Tree*)malloc(sizeof(Tree));
	data = (int*)malloc(sizeof(int) * N);

	for (int k = 0; k < N; k++) {
		scanf("%d", &data[k]);
	}
	//������������ ����
	qsort(data, N, sizeof(int), cmp);
	//���� ū ������ ���� ���� ��Ʈ�� �ڸ���(bit_level)�� �ִ´�.
	bit_level = find_high_bit(data[0]);
	//tree�� �����. left�� �ִ� ���� ���� ��Ʈ���� �����ؼ� 1�� �ش��ϴ� �����̴�.
	//right�� �ִ� ���� ���� ��Ʈ���� �����ؼ� 0�� �ش��ϴ� �����̴�.
	make_tree();
	printf("%d", calculate());
}