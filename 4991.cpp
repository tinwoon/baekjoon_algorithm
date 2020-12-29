#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <tuple>

//�̰� �÷��� �ƴ� ������?
//Ʋ������ ù��°: û�ұ⿡�� ���� ����� ���� ã�ư��� ���� �ּҰ��̶� ������
//Ʋ������ �ι�°: ������ ������ flood fill�� ���� ���� ���߾����(bfs�� �ϸ鼭 �ּڰ�ã�� x)
//������ ���ؼ� ��� ����� ���� û�ұⰡ ã�ư��� ����� ã�Ҿ����
int N, M;
//int dirty_count;
std::vector< std::vector<char> > map;
std::vector< std::vector<bool> > visited;
std::vector< std::pair<int, int> > dirty_place;
std::vector< std::vector<std::vector<int> > >value;
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { -1, 0, 1, 0 };

//i,j���� x,y�� �����ϴ� �ּҰ�
void bfs(int i, int j, int size, std::vector< std::vector<int> > &tmp) {
	//i,j, ����� ��. ��������� ���� Ƚ��
	std::queue< std::tuple<int,int,int> > q;
	visited.assign(N, std::vector<bool>(M, false));
	visited[i][j] = true;
	q.push(std::make_tuple(i, j, 0));
	

	while (!q.empty()) {
		auto front = q.front();
		int a, b, c;
		std::tie(a, b, c) = front;
		q.pop();
		
		for (int k = 0; k < 4; k++) {
			int nx = b + dx[k];
			int ny = a + dy[k];
					
			if (nx < M && nx >= 0 && ny < N && ny >= 0) {
				if (!visited[ny][nx]) {
					if (map[ny][nx] == 'x') continue;
					else {
						q.push(std::make_tuple(ny, nx, c + 1));
						tmp[ny][nx] = c + 1;
						visited[ny][nx] = true;
					}
				}
				
			}
			
		}

	}
	value.push_back(tmp);
}

int main() {

	while (1) {
		scanf("%d %d", &M, &N);
		if (N == 0 && M == 0) break;
		map.assign(N, std::vector<char>(M, 0));
		int rst = 100000001;

		std::pair<int, int> cleaner;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				scanf(" %1c", &map[i][j]);
				if (map[i][j] == 'o') cleaner = std::pair<int, int>(i, j);
				else if (map[i][j] == '*') {
					dirty_place.push_back(std::make_pair(i,j));
				}
			}
		}

		dirty_place.push_back(cleaner);
		std::reverse(dirty_place.begin(), dirty_place.end());
		std::vector<int> pmt;
		for (int i = 0; i < dirty_place.size(); i++) {
			pmt.push_back(i);
			std::vector< std::vector<int> > tmp(N, std::vector<int>(M, 0));
			bfs(dirty_place[i].first,dirty_place[i].second,i,tmp);
		}



		do {
			int min = 0;
			for (int i = 0; i < dirty_place.size()-1;i++) {
				//min += value[i][dirty_place[i].first][dirty_place[i].second] + value[i+1][dirty_place[i+1].first][dirty_place[i+1].second];
				int data = value[pmt[i]][dirty_place[pmt[i + 1]].first][dirty_place[pmt[i + 1]].second];
				if (data == 0) rst = -1; 
				min += data;
			}
			rst = std::min(min,rst);

		} while (std::next_permutation(pmt.begin()+1, pmt.end()));
		
		printf("%d\n", rst==0?-1:rst);
		dirty_place.clear();
		value.clear();
	}
}
