

//https://www.acmicpc.net/problem/2933
//진짜 이게 사람이 할 짓인가...
//시뮬은 요령도 없고 기술도 없는 것 같다...
//내 코드가 너무 길어서 의심했는데 난 70줄이나 짧은거였다
//왼쪽 아래 오른쪽으로 가서 바닥에 연결되어있는지 확인해야함
#include <iostream>
#include <vector>
#include <queue>

int R, C, N;
int dir = 1;
std::vector< std::vector<char> > map;
std::queue<int> order;

//x: 위아래 y: 왼쪽 오른쪽
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };


//얼마나 내려야하는지를 return하면 됨. ex) 2칸
int distance_with(std::vector<int> &low_floor) {
	
	for (int i = 0; i < C; i++) {
		int distance = 0;
		if (low_floor[i] < 100000) {
			for (int j = 1; R - low_floor[i] + j < R; j++) {
				//if (8 - low_floor[i] + j >= R) continue;
				if (map[R - low_floor[i] + j][i] == '.') {
					distance++;
				}else break;
			}
			low_floor[i] = distance;
		}
	}
	return *std::min_element(low_floor.begin(), low_floor.end());
}

//바닥에 붙어있는가
void is_attached(int i, int j) {
	std::vector< std::vector<bool> > attach_map(R, std::vector<bool>(C, false));
	std::queue< std::pair<int,int> > q;
	q.push(std::make_pair(i,j));
	attach_map[i][j] = true;
	//j층에 있는 가장 낮은 값
	std::vector<int> low_floor(C, 100000);
	low_floor[j] = R - i;

	while(!q.empty()){
		auto front = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = front.first + dx[i];
			int ny = front.second + dy[i];
			if (nx >= 0 && nx < R && ny >= 0 && ny < C) {
				if (!attach_map[nx][ny] && map[nx][ny] == 'x') {
					//1층에 도달했으면 잘릴 필요가 없기 때문
					if (nx == R - 1) return;
					q.push(std::make_pair(nx,ny));
					attach_map[nx][ny] = true;
					low_floor[ny] = std::min(low_floor[ny], R - nx);
				}                                           
			}
		}
	}	

	//여기까지 왔다는건 바닥면이 띄어져있고, attach_map에 띄어진 클러스터들이 true로 저장되어 있음
	//attached_map이 true인 것들을 바닥으로 내려야 함.
	//1층뿐 아닌 .까지도 확인해서 내려야 함 -> 코드 바꿔야함
	//int lowest = std::min_element(low_floor.begin(), low_floor.end());
	int lowest = distance_with(low_floor);
	for (int i = R - 1; i >= 0; i--) {
		for (int j = 0; j < C; j++) {
			if (attach_map[i][j] == true) {
				map[i][j] = '.';
				map[i + lowest][j] = 'x';
			}
		}
	}
	return;

}

void calculate() {
	while (!order.empty()) {
		int floor = order.front();
		order.pop();
		if (dir == 1) {
			for (int i = 0; i < C; i++) {
				if (map[R - floor][i] == 'x') {
					map[R - floor][i] = '.';
					for (int k = 0; k < 4; k++) {
						if (R - floor + dx[k] >= 0 && R - floor + dx[k] < R && i + dy[k] >= 0 && i + dy[k] < C && map[R - floor + dx[k]][i + dy[k]] == 'x') {
							is_attached(R - floor + dx[k], i + dy[k]);
						}
					}
					break;
				}
			}
			dir *= -1;
		}
		else {
			for (int i = C - 1; i >= 0; i--) {
				if (map[R - floor][i] == 'x') {
					map[R - floor][i] = '.';
					for (int k = 0; k < 4; k++) {
						if (R - floor + dx[k] >= 0 && R - floor + dx[k] < R && i + dy[k] >= 0 && i + dy[k] < C && map[R - floor + dx[k]][i + dy[k]] == 'x') {
							is_attached(R - floor + dx[k], i + dy[k]);
						}
					}
					break;
				}
			}
			dir *= -1;
		}
		
		/*printf("%d\n", order.size());
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				printf("%c", map[i][j]);
			}
			printf("\n");
		}*/
	}
	
	
}

int main() {
	scanf("%d %d", &R, &C);
	map.assign(R, std::vector<char>(C, 0));
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			scanf(" %1c", &map[i][j]);
		}
		getchar();
	}
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		int height;
		scanf("%d", &height);
		order.push(height);
	}
	calculate();
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			printf("%c", map[i][j]);
		}
		printf("\n");
	}

}


