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
//최대 상위 비트가 몇까지 같은지 알려준다.
//해당 비트가 같은게 없다면 그 다음 비트로 이동하는게 방법이다.
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
				//만약 넣으려하는데 노드가 없으면 노드 생성하기
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
				//만약 넣으려하는데 노드가 없으면 노드 생성하기
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
		//bit 최신화가 발생했는가?
		int bit_change_flag = 0;
		//현재까지 data[k]에 대한 값 중 가장 xor을 크게 만들 수 있는 값.
		int present_value = 0;
		Tree* pnode = root;
		if (data[k] & (1 << (b_l--))) {
			//오른쪽 비트가 없으면
			if (pnode->right == nullptr) {
				pnode = pnode->left;
				high_bit = b_l;
				bit_change_flag = 1;
			}
			//왼쪽 비트 확인
			else {
				pnode = pnode->right;
				present_value += (1 << (b_l + 1));
			}

			while (b_l >= 0) {
				//data[k]의 b_l비트가 1일때
				if (data[k] & (1 << (b_l--))) {
					//같은 비트가 0인 값이 있다면
					if (pnode->right != nullptr) {
						pnode = pnode->right;
						present_value += (1 << (b_l + 1));
					}
					//같은 비트가 0인 값이 없다면
					else {
						pnode = pnode->left;
						if (!bit_change_flag) {
							high_bit = b_l;
							//비트를 바꿨음을 공표
							bit_change_flag = 1;
						}
					}
				}
				//data[k]의 b_l비트가 0일때
				else {
					//같은 비트가 0인 값이 있다면
					if (pnode->left != nullptr) pnode = pnode->left;
					//같은 비트가 0인 값이 없다면
					else {
						pnode = pnode->right;
						present_value += (1 << (b_l + 1));
						if (!bit_change_flag) {
							high_bit = b_l;
							//비트를 바꿨음을 공표
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
	//내림차순으로 정렬
	qsort(data, N, sizeof(int), cmp);
	//제일 큰 값에서 가장 높은 비트의 자리수(bit_level)을 넣는다.
	bit_level = find_high_bit(data[0]);
	//tree를 만든다. left가 있는 경우는 상위 비트부터 시작해서 1에 해당하는 내역이다.
	//right가 있는 경우는 상위 비트부터 시작해서 0에 해당하는 내역이다.
	make_tree();
	printf("%d", calculate());
}