#pragma warning (disable : 4996)
#include <iostream>
#include <vector>

//백준 1507 궁금한 민호
//플로이드 와셜 문제이며, 무방향 그래프이므로, 전체 i,j에 대한 검색할 필요 없이 i < j에 대한 인덱스만 확인함.
// 이미 삭제한 경로에 대해서는 visited를 통해 재 삭제할 가능성을 배재시킴.

int N;
int full_road_time;
std::vector< std::vector<int> > data;
std::vector< std::vector<bool> > visited;

int calculate() {
	for (int k = 0; k < N; k++) {
		for (int i = 0; i < N; i++) {
			for (int j = i + 1; j < N; j++) {
				if (i != k && k != j) {
					if (data[i][j] == data[i][k] + data[k][j] && !visited[i][j]) {
						full_road_time -= data[i][j];
						visited[i][j] = true;
					}
					else if (data[i][j] > data[i][k] + data[k][j]) return -1;
				}
			}
		}
	}

	return full_road_time;
}

int main() {
	scanf("%d", &N);
	data.assign(N, std::vector<int>(N, 0));
	visited.assign(N, std::vector<bool>(N, false));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &data[i][j]);
			if (i < j) full_road_time += data[i][j];
		}
	}

	printf("%d", calculate());
}