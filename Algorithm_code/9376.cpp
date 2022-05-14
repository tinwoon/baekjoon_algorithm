#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>

//1. 숨바꼭질 3의 문제는 가중치 bfs인데 당시는 queue 2개로 풀음
//2. 이 역시도 가중치 bfs로 queue 2개와 deque 한개로 푸는 방법이 있는데 deque로 푸는게 더 쉬우니 숨바꼭질 3의 deque 코드 보기
//3. 하나의 중점에서 만나는 걸 기준으로 죄수 1에서 bfs , 죄수 2에서 bfs , 탈출점에서 bfs 한 가중치 값을 따로 계산 (value_1, 2,3에 저장)
//4. 어떤 노드에서 value_1,2,3의 값을 더하면 해당 지점이 가장 빠르게 갈 수 있는 최솟값임.


std::vector< std::vector<int> > map;
std::vector< std::pair<int, int> > prisoner;
std::vector< std::vector<int> > value_1;
std::vector< std::vector<int> > value_2;
std::vector< std::vector<int> > value_3;
int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };
int N, M;

//i,j는 시작점
void bfs(int i, int j, std::vector< std::vector<int> > &value) {
	std::deque< std::pair<int, int> >q;
	q.push_front(std::make_pair(i, j));
	value[i][j] = 0;

	while(!q.empty()){
		auto front = q.front();
		q.pop_front();

		for (int k = 0; k < 4; k++) {
			int nx = front.second + dx[k];
			int ny = front.first + dy[k];
			if (nx >= 0 && nx < M + 2 && ny >= 0 && ny < N + 2) {
				if ( map[ny][nx] != '*') {
					if (value[ny][nx] != -1) continue;
					if (map[ny][nx] == '#') {
						value[ny][nx] = value[front.first][front.second] + 1;
						q.push_back(std::make_pair(ny, nx));
					}
					else {
						value[ny][nx] = value[front.first][front.second];
						q.push_front(std::make_pair(ny, nx));
					}
				}
			}
		}
	}
	
	
}


int main() {
	int test_num;
	scanf("%d", &test_num);
	while (test_num--) {
		int rst = 1000000001;
		scanf("%d %d", &N, &M);
		map.assign(N + 2, std::vector<int>(M + 2, 0));
		value_1.assign(N + 2, std::vector<int>(M + 2, -1));
		value_2.assign(N + 2, std::vector<int>(M + 2, -1));
		value_3.assign(N + 2, std::vector<int>(M + 2, -1));

		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= M; j++) {
				scanf(" %1c", &map[i][j]);
				if (map[i][j] == '$') prisoner.push_back(std::make_pair(i,j));
			}
		}

		bfs(0, 0, value_1);
		bfs(prisoner[0].first, prisoner[0].second, value_2);
		bfs(prisoner[1].first, prisoner[1].second, value_3);

		for (int i = 0; i <= N + 1; i++) {
			for (int j = 0; j <= M + 1; j++) {
				if (map[i][j] == '*') continue;
				value_1[i][j] += value_2[i][j] + value_3[i][j];
				if (map[i][j] == '#') value_1[i][j] -= 2;
				if (value_1[i][j] == -3) continue;
				rst = std::min(rst, value_1[i][j]);
			}
		}
		printf("%d\n", rst);
		prisoner.clear();
	}
}
