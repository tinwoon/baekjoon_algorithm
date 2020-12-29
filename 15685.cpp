#include <iostream>
#include <vector>

std::vector< std::vector<bool> >map(101, std::vector<bool>(101, false));
int x, y, d, g;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,-1,0,1 };
int rst = 0;

void calculate() {
	std::vector< std::pair<int, int> > location;
	location.push_back(std::make_pair(y, x));
	location.push_back(std::make_pair(y + dy[d], x + dx[d]));
	map[y][x] = true;
	map[y + dy[d]][x + dx[d]] = true;
	while (g--) {
		auto finish = location.back();	
		for (int i = location.size() - 2; i >=0 ; i--) {
			int ny = finish.first + location[i].second - finish.second;
			int nx = finish.second + finish.first - location[i].first;
			location.push_back(std::make_pair(ny, nx));
			map[ny][nx] = true;
		}
	}

}

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d %d %d", &x, &y, &d, &g);
		calculate();
	}

	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			if (map[i][j] && map[i + 1][j] && map[i][j + 1] && map[i + 1][j + 1]) rst++;
		}
	}
	printf("%d", rst);


}
