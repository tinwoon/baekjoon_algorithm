#pragma warning (disable : 4996)
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

int N, S, W;
//S, W
//내구도, 무게
std::vector< std::pair<int, int> > data;
int ans = 0;

int ret() {
	std::pair<int, int> hand = data[0];
	int index = 1;

	int hand_s = hand.first;
	int hand_w = hand.second;

	int index_s = data[index].first;
	int index_w = data[index].second;

	while (1) {
		int hit_hand_s = hand_s - index_w;
		int hit_index_s = index_s - hand_s;

		if (hit_hand_s)
	}
}

void calculate() {
	do {

	} while (std::next_permutation(data.begin(), data.end()));
}

int main() {
	scanf("%d", &N);
	for (int k = 0; k < N; k++) {
		int S, W;
		scanf("%d %d", &S, &W);
		data.emplace_back(std::make_pair(S, W));
	}

	std::sort(data.begin(), data.end());

}