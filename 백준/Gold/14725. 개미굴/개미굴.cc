#pragma warning (disable : 4996)
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>



typedef struct Node{
	std::string meal;
	std::vector< struct Node* > children;
} Node;

int N;
Node* last_node;

bool cmp(Node* a, Node* b) {
	return (a->meal < b->meal);
}

void observe_trie(int level, Node* node) {

	if (node->meal != "") {
		for (int k = 0; k < level - 1; k++) {
			std::cout << "--";
		}
		std::cout << node->meal << std::endl;
	}
	

	std::sort(node->children.begin(), node->children.end(), cmp);

	for (int idx = 0; idx < node->children.size(); idx++) {
		observe_trie(level + 1, node->children[idx]);
	}
}

void insert_trie_node(Node* node, std::string s) {
	bool find_s = false;
	

	for (int size = 0; size < node->children.size(); size++) {
		if (find_s = (node->children[size]->meal == s)) {
			last_node = node->children[size];
			break;
		}
	}

	if (!find_s) {
		Node* n_node = new Node();
		n_node->meal = s;
		node->children.emplace_back(n_node);
		last_node = n_node;
	}
}

int main() {
	std::cin >> N;
	Node* root = new Node();

	for (int k = 0; k < N; k++) {
		int M;
		std::cin >> M;

		last_node = root;

		for (int idx = 0; idx < M; idx++) {
			std::string s;
			std::cin >> s;
			insert_trie_node(last_node, s);
		}
	}

	observe_trie(0, root);
}