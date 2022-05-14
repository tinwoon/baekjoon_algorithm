//������ �����ð��� ����ߴ� ����
//��ͷ� ����� ���� ã�� �˰����� ����� ���� �� �� �ִ�.
//https://www.acmicpc.net/problem/15683
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <tuple>

int N, M;
int rst = 100;
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };
std::vector< std::vector<int> > map;

//cctv�� ��, ��, cctv ����
std::queue< std::tuple<int, int, int> > cctv;
std::vector<int> direct;



void calculate(int num_cctv) {

	if (num_cctv == direct.size()) {
		auto cctv_cpy = cctv;
		auto map_cpy = map;
		//std::vector< std::vector<bool> > visited(N, std::vector<bool>(M, false));

		while (!cctv_cpy.empty()) {
			auto present = cctv_cpy.front();
			cctv_cpy.pop();

			//������ q���� ������ ���� ���̴�.
			std::queue< std::tuple<int, int, int> > q;
			
				//cctv��ȣ�� ����
			int direct_value = direct[cctv.size() - cctv_cpy.size() - 1];
			switch (std::get<2>(present)) {
				case 1:
					q.push(std::make_tuple(std::get<0>(present), std::get<1>(present), direct_value));
					break;
				case 2:
					q.push(std::make_tuple(std::get<0>(present), std::get<1>(present), direct_value));
					q.push(std::make_tuple(std::get<0>(present), std::get<1>(present), (direct_value + 2) % 4));
					break;
				case 3:
					q.push(std::make_tuple(std::get<0>(present), std::get<1>(present), direct_value));
					q.push(std::make_tuple(std::get<0>(present), std::get<1>(present), (direct_value + 1) % 4));
					break;
				case 4:
					q.push(std::make_tuple(std::get<0>(present), std::get<1>(present), direct_value));
					q.push(std::make_tuple(std::get<0>(present), std::get<1>(present), (direct_value + 1) % 4));
					q.push(std::make_tuple(std::get<0>(present), std::get<1>(present), (direct_value + 3) % 4));
					break;
				case 5:
					q.push(std::make_tuple(std::get<0>(present), std::get<1>(present), direct_value));
					q.push(std::make_tuple(std::get<0>(present), std::get<1>(present), (direct_value + 1) % 4));
					q.push(std::make_tuple(std::get<0>(present), std::get<1>(present), (direct_value + 2) % 4));
					q.push(std::make_tuple(std::get<0>(present), std::get<1>(present), (direct_value + 3) % 4));
					break;
			}
			
			while (!q.empty()) {
				auto front = q.front();
				q.pop();

				//cctv�� ��, ��, cctv ����
				int x, y, cctv_direct;
				std::tie(x, y, cctv_direct) = front;

				int nx = x + dx[cctv_direct];
				int ny = y + dy[cctv_direct];
					
				if (nx >= 0 && nx < N && ny >= 0 && ny < M) {
					if (map_cpy[nx][ny] != 6) {
						map_cpy[nx][ny] = 7;
						q.push(std::make_tuple(nx, ny, cctv_direct));
					}
				}
			}
		}
		
		int tmp = 0;
		for (int i = 0; i < N; i++) {
			tmp += std::count(map_cpy[i].begin(), map_cpy[i].end(), 0);
		}
		if (rst > tmp) rst = tmp;
	}
	
	else {
		for (int k = 0; k < 4; k++) {
			direct[num_cctv] = k;
			calculate(num_cctv + 1);
		} 
	}
	
}


int main() {
	scanf("%d %d", &N, &M);
	map.assign(N, std::vector<int>(M, 0));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &map[i][j]);
			if (map[i][j] >= 1 && map[i][j] <= 5) {
				cctv.push(std::make_tuple(i,j,map[i][j]));
			}
		}
	}
	direct.assign(cctv.size(),0);
	calculate(0);
	printf("%d", rst);
}
