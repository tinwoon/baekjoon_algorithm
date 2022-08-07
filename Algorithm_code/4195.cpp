#pragma warning (disable : 4996)
#include <iostream>
#include <vector>
#include <map>
#include <string>

//4195 친구 네트워크 문제
//전형적인 Union-find로 어려운 부분은 없었다.
//이름, 이름에 해당 하는 부모, 친구네트워크 수
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

	//b의 값을 변경해야한다.
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