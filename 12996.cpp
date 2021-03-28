#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

//dp문제이니 설명 생략. 

int S, A_song, B_song, C_song;
int dp[51][51][51][51];
bool visited[51][51][51][51];

inline void calculate(int s,int need_to_song_A, int need_to_song_B, int need_to_song_C) {

	std::queue < std::tuple <int, int, int, int> > q;
	q.emplace(std::make_tuple(s, need_to_song_A, need_to_song_B, need_to_song_C));
	
	while (!q.empty()) {
		auto front = q.front();
		q.pop();
		std::tie(s, need_to_song_A, need_to_song_B, need_to_song_C) = front;

		if (need_to_song_A == 0 && need_to_song_B == 0 && need_to_song_C == 0 && s == 0) continue;
		if (visited[s][need_to_song_A][need_to_song_B][need_to_song_C]) continue;

		for (int i = 1; i < (1 << 3); i++) {
			int a = need_to_song_A - ((i & (1 << 2)) / 4);
			int b = need_to_song_B - ((i & (1 << 1)) / 2);
			int c = need_to_song_C - (i & (1 << 0));
			if (a < 0 || b < 0 || c < 0 || s - 1 < 0) continue;
			if (s - 1 > 0 && a == 0 && b == 0 && c == 0) continue;
			dp[s - 1][a][b][c] = (dp[s - 1][a][b][c] + dp[s][need_to_song_A][need_to_song_B][need_to_song_C]) % 1000000007;
			visited[s][need_to_song_A][need_to_song_B][need_to_song_C] = true;
			q.emplace(std::make_tuple(s - 1, a, b, c));
		}
	}
	
}

int main() {
	scanf("%d %d %d %d", &S, &A_song, &B_song, &C_song);
	dp[S][A_song][B_song][C_song] = 1;
	calculate(S, A_song, B_song, C_song);
	printf("%d", dp[0][0][0][0]);
}
