#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <string>
#include <algorithm>


//오래걸린 이유
//디버깅이 릴리즈보다 몇초이상 느릴 수 있음을 기억하기
std::map <std::string, int> visited;
std::string initialize_value;
std::string rst = "123456780";
int dx[4] = { -1, 1, 0 ,0 };
int dy[4] = { 0, 0, -1, 1 };



void bfs() {
	std::queue<std::string> q;
	q.push(initialize_value);
	visited.insert(std::pair<std::string, int>(initialize_value, 0));
	int index = 0;
	std::string value;

	while (!q.empty()) {
		value = q.front();
		index = value.find('0');
		int x = index % 3;
		int y = index / 3;
		int nx, ny;
		
		if (value == rst) {
			printf("%d", visited[value]);
			exit(0);
		}

		for (int i = 0; i < 4; i++) {
			nx = x + dx[i];
			ny = y + dy[i];
			std::string tmp = value;
			if (nx < 3 && nx >= 0 && ny < 3 && ny >= 0) {
				std::swap( tmp[index], tmp[ny*3+nx] );
				if (visited.count(tmp) == 0) {
					visited.insert(std::pair<std::string, int>(tmp, visited[value] + 1));
					q.push(tmp);
				}
			}
		}
		q.pop();
	}
	printf("%d", -1);
}


int main() {
	
	char c;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			std::cin >> c;
			initialize_value += c;
		}
	}
	bfs();
}

