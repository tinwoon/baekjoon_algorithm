#pragma warning (disable : 4996)
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <numeric>

//16987 계란으로 계란치기 
//dfs를 통한 백트래킹

int N, S, W;
//S, W
//내구도, 무게
std::vector< std::pair<int, int> > data;
int ans = 0;

void dfs(int hand_index, int destroy) {

	ans = std::max(ans, destroy);

	//더 이상 들게 없거나, 모든 계란이 파괴됐으면 종료한다.
	if (hand_index == N || destroy == N) return;

	if (data[hand_index].first <= 0) {
		dfs(hand_index + 1, destroy);
		return;
	}

	for (int k = 0; k < N; k++) {
		if (hand_index == k || data[k].first <= 0) continue;

		data[hand_index].first -= data[k].second;
		data[k].first -= data[hand_index].second;
		int destroy_p = 0;
		if (data[hand_index].first <= 0) destroy_p++;
		if (data[k].first <= 0) destroy_p++;

		dfs(hand_index + 1, destroy + destroy_p);
		data[hand_index].first += data[k].second;
		data[k].first += data[hand_index].second;
	}

}


int main() {
	scanf("%d", &N);
	for (int k = 0; k < N; k++) {
		int S, W;
		scanf("%d %d", &S, &W);
		data.emplace_back(std::make_pair(S, W));
	}

	dfs(0, 0);
	printf("%d", ans);

}