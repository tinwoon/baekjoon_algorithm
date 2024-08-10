#pragma warning (disable : 4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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