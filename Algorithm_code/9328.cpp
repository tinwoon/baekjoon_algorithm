#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>


//벽에서 기다리는 방식을 사용해야함

std::vector< std::vector<char> > map;
std::vector< std::vector<int> > value;
std::vector< std::vector<bool> > visited;
std::vector<bool> alphabet_key;
int N, M;
int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };

int bfs(int i, int j) {
	std::queue< std::pair<int, int> > q;
	q.push(std::make_pair(i, j));
	std::queue< std::pair<int,int> > wait_q[26];
	int rst = 0;

	while (!q.empty()) {
		auto front = q.front();
		q.pop();


		for (int k = 0; k < 4; k++) {
			int nx = front.second + dx[k];
			int ny = front.first + dy[k];
			
			if (nx >= 0 && nx < M + 2 && ny >= 0 && ny < N + 2 ) {
				char v = map[ny][nx];
				//벽이라면
				if (v == '*' || visited[ny][nx]) continue;
				visited[ny][nx] = true;

				//알파벳이라면
				//printf("%d %d\n",map[ny][nx], isalpha(map[ny][nx]));
				if (isalpha(v)) {
					//대문자라면
					if (isupper(v)) {
						if (alphabet_key[v - 'A']) {
							map[ny][nx] = '.';
							q.push(std::make_pair(ny, nx));
						}
						else wait_q[v - 'A'].push(std::make_pair(ny, nx));
					}
					//소문자라면
					else {
						alphabet_key[v - 'a'] = true;
						map[ny][nx] = '.';
						q.push(std::make_pair(ny, nx));
						while (!wait_q[v - 'a'].empty()) {
							q.push(wait_q[v - 'a'].front());
							wait_q[v - 'a'].pop();
						}
						
					}
				}
				//문서라면
				else if(v == '$'){
					map[ny][nx] = '.';
					q.push(std::make_pair(ny, nx));
					rst++;
				}
				else q.push(std::make_pair(ny, nx));
			}
		}
	}
	
	return rst;
}



int main() {
	int test;
	scanf("%d", &test);
	while (test--) {
		scanf("%d %d", &N, &M);
		map.assign(N + 2, std::vector<char>(M + 2, 0));
		value.assign(N + 2, std::vector<int>(M + 2, 0));
		visited.assign(N + 2, std::vector<bool>(M + 2, false));
		alphabet_key.assign(26, false);
		for (int i = 1; i < N + 1; i++) {
			for (int j = 1; j < M + 1; j++) {
				scanf(" %1c", &map[i][j]);
			}
		}
		std::string c;
		std::cin >> c;
		if (c != "0") {
			for (int i = 0; i < c.size(); i++) {
				alphabet_key[c[i] - 'a'] = true;
			}
		}
		printf("%d\n", bfs(0,0));

	}
}
