#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
#include <tuple>

int N, M;
std::vector< std::vector<char> > map;
std::vector< std::pair<int, int> > coin;
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };
int rst = 10000000;

void calculate(int count, int coin_1_x, int coin_1_y, int coin_2_x, int coin_2_y) {

	if (count > 10 || count > rst) {
		return;
	}

	for (int k = 0; k < 4; k++) {
		int is_ok = 0;
		bool coin_1_move = false;
		bool coin_2_move = false;

		int nx = coin_1_x + dx[k];
		int ny = coin_1_y + dy[k];
		if (nx >= 0 && nx < N && ny >= 0 && ny < M) {
			if (map[nx][ny] != '#') coin_1_move = true;
		}
		else is_ok++;

		nx = coin_2_x + dx[k];
		ny = coin_2_y + dy[k];
		if (nx >= 0 && nx < N && ny >= 0 && ny < M) {
			if (map[nx][ny] != '#') coin_2_move = true;
		}
		else is_ok++;

		if (is_ok == 1) {
			rst = std::min(rst, count);
		} 
		else if (is_ok == 2) continue;

		if (coin_1_move) {
			if(coin_2_move) calculate(count + 1, coin_1_x + dx[k], coin_1_y + dy[k], coin_2_x + dx[k], coin_2_y + dy[k]);
			else calculate(count + 1, coin_1_x + dx[k], coin_1_y + dy[k], coin_2_x, coin_2_y);
		}
		else {
			if (coin_2_move) calculate(count + 1, coin_1_x, coin_1_y, coin_2_x + dx[k], coin_2_y + dy[k]);
			else calculate(count + 1, coin_1_x, coin_1_y, coin_2_x, coin_2_y);
		}
		
	}
	


}


int main() {
	scanf("%d %d", &N, &M);
	map.assign(N, std::vector<char>(M, 0));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf(" %1c", &map[i][j]);
			if (map[i][j] == 'o') coin.push_back(std::make_pair(i, j));
		}
	}
	calculate(1, coin[0].first, coin[0].second, coin[1].first, coin[1].second);
	if (rst == 10000000) printf("-1");
	else printf("%d", rst);
}
