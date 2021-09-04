#pragma warning (disable : 4996)
#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>

//1976 여행가자
//유니온 파인드 문제 

int N, M;
std::vector<int> parent;
std::vector<int> trip_road;

int get_parent(int node) {
	if (parent[node] == node) return node;
	else return parent[node] = get_parent(parent[node]);
}

void union_n(int a, int b) {
	a = get_parent(a);
	b = get_parent(b);
	if (a > b) parent[a] = b;
	else parent[b] = a;
}

int find(int a, int b) {
	if (get_parent(a) == get_parent(b)) return true;
	else return false;
}

int main() {
	scanf("%d", &N);
	scanf("%d", &M);
	parent.assign(N, 0);
	trip_road.assign(M, 0);
	for (int k = 0; k < N; k++) {
		parent[k] = k;
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int to_node;
			scanf("%d", &to_node);
			if (to_node) union_n(i, j);
		}
	}
	bool flag = true;
	for (int k = 0; k < M; k++) {
		scanf("%d", &trip_road[k]);
		trip_road[k]--;
	}
	std::sort(trip_road.begin(), trip_road.end());
	for (int k = 1; k < M; k++) {
		if (!find(trip_road[k], trip_road[0])) {
			flag = false;
			break;
		}
	}
	if (flag) printf("YES\n");
	else printf("NO\n");
}
