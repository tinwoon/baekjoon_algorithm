#include <iostream>
#include <vector>
#include <set>
#include <tuple>
#include <algorithm>
#include <limits.h>
#include <queue>

int N, M;
char map[51][51];
std::set<int> alphabet;
//i번 알파벳의 상 하 좌 우 좌표
std::tuple<int, int, int, int> node_loc[256] = { std::tuple<int,int,int,int>(0,0,0,0), };
//n번 노드를 들어오는 노드는 무엇이 있는가(outdegree)
std::set<int> outdegree[256];
//n번 노드 안에는 무엇이 있는가(indegree)
std::set<int> indegree[256];
//n번 노드의 indegree수는 몇인가.
int indegree_num[256] = { INT_MAX, };
std::string ans = "";

//각 노드의 indegree의 개수를 저장한다.
void cal_indegree() {
	for (int k = 0; k < 256; k++) {
		indegree_num[k] = indegree[k].size();
	}
}

//위상정렬
std::string sort_t() {
	std::priority_queue< int, std::vector<int>, std::greater<int> > q;
	for (int k = 0; k < 256; k++) {
		if (indegree_num[k] == 0) q.emplace(k);
	}

	while (!q.empty()) {
		auto front = q.top();
		ans += (char)front;
		q.pop();
		
		for (auto itr = outdegree[front].begin(); itr != outdegree[front].end(); itr++) {
			indegree_num[*itr]--;
			if (indegree_num[*itr] == 0) {
				q.emplace(*itr);
			}
		}
	}
	if (ans.size() != alphabet.size()) ans = "-1";
	return ans;
}

//각 노드들의 indegree, outdegree를 구한다.
void calculate() {
	for (auto itr = alphabet.begin(); itr != alphabet.end(); itr++) {
		int top, down, left, right;
		std::tie(top, down, left, right) = node_loc[*itr];
		for (int i = top; i <= down; i++) {
			for (int j = left; j <= right; j++) {
				if (map[i][j] == *itr || map[i][j] == '.') continue;
				outdegree[map[i][j]].emplace(*itr);
				indegree[*itr].emplace(map[i][j]);
			}
		}
	}
}

//각 노드들의 좌표를 찾는다.
void loc() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == '.') continue;
			int top, down, left, right;
			std::tie(top, down, left, right) = node_loc[map[i][j]];
			top = top != 0 ? std::min(i, top) : top;
			down = std::max(i, down);
			left = left != 0 ? std::min(j, left) : left;
			right = std::max(j, right);
			node_loc[map[i][j]] = std::make_tuple(top, down, left, right);
		}
	}
}


int main() {
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf(" %1c", &map[i][j]);
			if (map[i][j] != '.') alphabet.emplace(map[i][j]);
		}
	}
	loc();
	calculate();
	cal_indegree();
	printf("%s", sort_t());
}
