#pragma warning (disable : 4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//5052 전화번호 목록 문제
//kmp 접두사로 접근했다가 Tree 문제라는 것을 깨닫게 됨.
//C언어를 기반으로 malloc을 통한 할당 시 메모리 해제가 꼭 필요함을 확인할 수 있었다.

int t, n;

typedef struct Tree {
	struct Tree* child[10];
}Tree;

Tree* root;

Tree* init_tree() {
	Tree* node = (Tree*)malloc(sizeof(Tree));
	for (int k = 0; k < 10; k++) {
		node->child[k] = NULL;
	}
	return node;
}

Tree* make_tree(Tree* node, int num) {
	if (node->child[num] == NULL)
	{
		Tree* make_node = init_tree();
		node->child[num] = make_node;
		return make_node;
	}
	else return node->child[num];
}

void delete_Tree(Tree* rt) {
	Tree* child[10];
	for (int k = 0; k < 10; k++) {
		child[k] = rt->child[k];
		if (child[k] != NULL) delete_Tree(child[k]);
	}
	free(rt);
	return;
}

int calculate(char (*nb)[10001]) {
	Tree* node;
	for (int i = 0; i < n; i++) {
		node = root;
		int size = strlen(nb[i]);
		for (int j = 0; j < size; j++) {
			node = node->child[nb[i][j] - '0'];
		}
		for (int k = 0; k < 10; k++) {
			if (node->child[k] != NULL) return 0;
		}
	}
	return 1;
}


int main() {
	scanf("%d", &t);
	for (int i = 0; i < t; i++) {
		root = init_tree();
		scanf("%d", &n);
		char(*number)[10001];
		number = (char(*)[10001])malloc(sizeof(char) * n * 10001);
		for (int j = 0; j < n; j++) {
			int size = 0;
			scanf("%s", number[j]);
			size = strlen(number[j]);
			Tree* node = root;
			for (int k = 0; k < size; k++) {
				node = make_tree(node, number[j][k] - '0');
			}
		}
		printf("%s", calculate(number) ? "YES\n" : "NO\n");
		delete_Tree(root);
		free(number);
	}
}