

//https://www.acmicpc.net/problem/2933
//��¥ �̰� ����� �� ���ΰ�...
//�ù��� ��ɵ� ���� ����� ���� �� ����...
//�� �ڵ尡 �ʹ� �� �ǽ��ߴµ� �� 70���̳� ª���ſ���
//���� �Ʒ� ���������� ���� �ٴڿ� ����Ǿ��ִ��� Ȯ���ؾ���
#include <iostream>
#include <vector>
#include <queue>

int R, C, N;
int dir = 1;
std::vector< std::vector<char> > map;
std::queue<int> order;

//x: ���Ʒ� y: ���� ������
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };


//�󸶳� �������ϴ����� return�ϸ� ��. ex) 2ĭ
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

//�ٴڿ� �پ��ִ°�
void is_attached(int i, int j) {
	std::vector< std::vector<bool> > attach_map(R, std::vector<bool>(C, false));
	std::queue< std::pair<int,int> > q;
	q.push(std::make_pair(i,j));
	attach_map[i][j] = true;
	//j���� �ִ� ���� ���� ��
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
					//1���� ���������� �߸� �ʿ䰡 ���� ����
					if (nx == R - 1) return;
					q.push(std::make_pair(nx,ny));
					attach_map[nx][ny] = true;
					low_floor[ny] = std::min(low_floor[ny], R - nx);
				}                                           
			}
		}
	}	

	//������� �Դٴ°� �ٴڸ��� ������ְ�, attach_map�� ����� Ŭ�����͵��� true�� ����Ǿ� ����
	//attached_map�� true�� �͵��� �ٴ����� ������ ��.
	//1���� �ƴ� .������ Ȯ���ؼ� ������ �� -> �ڵ� �ٲ����
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


