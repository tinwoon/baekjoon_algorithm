#include <iostream>
#include <vector>

int rst = 0;
int N, L;
std::vector< std::vector<int> >map;
std::vector< std::vector<bool> >set;

//평평한가
bool is_down_flat(int i, int j) {
	if (j + L >= N) return false;
	for (int k = 1; k <= L; k++) {
		if (map[i][j] != map[i][j + k] + 1 || set[i][j + k]) return false;
		set[i][j + k] = true;
	}
	return true;
}

bool is_up_flat(int i, int j) {
	if (j - L + 1 < 0) return false;
	for (int k = 0 ; k < L; k++) {
		if (map[i][j + 1] != map[i][j - k] + 1 || set[i][j - k]) return false;
		set[i][j - k] = true;
	}
	return true;
}

//높이가 1이하로 차이나는가
bool is_height(int i, int j) {
	if (map[i][j + L] == map[i][j] + 1 || map[i][j + L] == map[i][j] - 1) return true;
	else return false;
}


void calculate() {

	for (int i = 0; i < N; i++) {
		bool flag = false;
		for (int j = 0; j < N-1; j++) {
			if (map[i][j] > map[i][j+1]) {
				if (!is_down_flat(i, j)) {
					flag = true;
					break;
				}
			}
			else if (map[i][j] < map[i][j + 1]) {
				if (!is_up_flat(i, j)) {
					flag = true;
					break;
				} 
			}
		}
		if(!flag) rst++;
	}

}


int main() {
	scanf("%d %d", &N, &L);
	map.assign(N, std::vector<int>(N, 0));
	set.assign(N, std::vector<bool>(N, false));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &map[i][j]);
		}
	}
	calculate();
	auto tmp = map;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			tmp[j][i] = map[i][j];
		}
	}
	map = tmp;
	set.assign(N, std::vector<bool>(N, false));
	calculate();
	//printf("%d", set[1][1]);

	printf("%d", rst);
}
