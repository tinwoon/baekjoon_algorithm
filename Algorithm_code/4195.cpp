#pragma warning (disable : 4996)
#include <iostream>
#include <vector>
#include <map>
#include <string>

//4195 ģ�� ��Ʈ��ũ ����
//�������� Union-find�� ����� �κ��� ������.
//�̸�, �̸��� �ش� �ϴ� �θ�, ģ����Ʈ��ũ ��
std::map<std::string, int> index;
std::vector<int> parent;
std::vector<int> depth;

int t;
int F;

int get_index(std::string frnd) {
	if (index.insert(std::make_pair(frnd, index.size())).second) {
		parent.emplace_back(parent.size());
		depth.emplace_back(1);
		return parent.size() - 1;
	}
	return index[frnd];
	
}

int get_parent(int node) {
	if (node == parent[node]) return node;
	return get_parent(parent[node]);
}

bool find(int node_one, int node_two) {
	return get_parent(node_one) == get_parent(node_two);
}

void union_n(int node_one, int node_two) {
	int a = get_parent(node_one);
	int b = get_parent(node_two);

	//b�� ���� �����ؾ��Ѵ�.
	if (a < b) {
		parent[b] = a;
		depth[b] = depth[a] += depth[b];
	}
	else {
		parent[a] = b;
		depth[a] = depth[b] += depth[a];
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	std::cin >> t;
	while (t--) {
		index.clear();
		parent.clear();
		depth.clear();
		std::cin >> F;
		while (F--) {
			std::string friend_one, friend_two;
			std::cin >> friend_one >> friend_two;
			int idx_one = get_index(friend_one);
			int idx_two = get_index(friend_two);
			if (!find(idx_one, idx_two)) {
				union_n(idx_one, idx_two);
			}
			printf("%d\n", depth[get_parent(idx_one)]);
		}
	}
}