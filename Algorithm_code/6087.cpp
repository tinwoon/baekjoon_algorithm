#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <tuple>

//https://www.acmicpc.net/problem/6087
//Ʋ������ ���� ù����: visited�� ����ϸ� push_back�� ���� �ſﰪ�� +1�ؼ� �ִ��� 
// �ſ��� ���� ���� ���߿� �����Ϸ��ϸ� visited�� true�� �Ǿ��־ �������� ����
// ���� ��� ������ �������� (5,3)�� �ش��ϴ� �ſ� ���� 4�� ������ ���� ���Ѵ�.
// �� �� ���� ������ (5,2)�� Ȯ���ϰ� visited[5][2]�� true�� �ϸ� ť�� push_back���� �־ �켱������ �ڷ� �Ѵ�.
// ���� q�� ������ �ſ� ���� ����ġ�� 4�� �� ������ �Ǳ�� ������ visited[5][2]�� true�� �Ǿ��� ������ 
// (6,2)���� ���� �ö���� ����ġ�� 4�ӿ��� �ұ��ϰ� visited[5][2]�� true�� �Ǿ��־ value[5][2]�� 4�� ���� ���Ѵ�.
// �� �ſ��� �� ���� �� �� �������� �湮�� �ʰ��� ���� ſ�� ������ü�� ���� �ʰ� ������ ������ ���Ѵ�.
// ���� 
//if (value[ny][nx] > -1 && value[ny][nx] < data + 1) {
//	continue;
//}
//���� ���� ���ؼ� value�� -1�̸� �湮���� ������, �̹� ���� value���� ���� ���� value������ ������ �����ϸ� �ȴ�.
//�̷��� ���籸�� value���� ������ ���� ���� ���� �� �ִ�.

std::vector< std::vector<char> >map;
std::vector< std::pair<int, int> >laser;
//std::vector< std::vector<bool> >visited;
std::vector< std::vector<int> >value;

int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };
int N, M;

void bfs() {
	std::deque< std::tuple<int, int, int, int> > q;
	//������ Ž���� k�� ��, �ſ��� ����
	q.push_front(std::make_tuple(laser[0].first,laser[0].second, -1,0));
	//visited[laser[0].first][laser[0].second] = true;
	value[laser[0].first][laser[0].second] = 0;

	while (!q.empty()) {
		auto front = q.front();
		q.pop_front();
		int x, y, z, data;
		std::tie(x, y, z, data) = front;

		/*if (x == laser[1].first && y == laser[1].second) {
			printf("%d", value[0][0]);
			return data;
		}*/
		
		for (int k = 0; k < 4; k++) {
			int ny = x + dy[k];
			int nx = y + dx[k];
			if (nx >= 0 && nx < M && ny >= 0 && ny < N) {
				if (map[ny][nx] == '*') continue;
				
				//�̵��� ������ ���ٸ�
				if (z == k) {
					if (value[ny][nx] > -1 && value[ny][nx]<data) {
						continue;
					}
					else {
						q.push_front(std::make_tuple(ny, nx, k, data));
						value[ny][nx] = data;
					}
				}
				else {
					if (value[ny][nx] > -1 && value[ny][nx] < data + 1) {
						continue;
					}
					else {
						q.push_back(std::make_tuple(ny, nx, k, data + 1));
						value[ny][nx] = data + 1;
					}
				}
			}
				
			
		}
	}

}

int main() {
	scanf("%d %d",&M, &N);
	map.assign(N, std::vector<char>(M, 0));
	//visited.assign(N, std::vector<bool>(M, false));
	value.assign(N, std::vector<int>(M, -1));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf(" %1c", &map[i][j]);
			if (map[i][j] == 'C') laser.push_back(std::make_pair(i,j));
		}
	}
	bfs();
	printf("%d\n", value[laser[1].first][laser[1].second]-1);
}
