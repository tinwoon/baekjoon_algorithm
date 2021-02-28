#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <tuple>

//bfs로 모든 경우의 수를 확인하지만, 각각의 하노이 층에 무엇이 있는지 확인하는 단순 알고리즘
std::vector< std::vector<char> > column(3,std::vector<char>());
std::set< std::tuple< std::vector<char>, std::vector<char>, std::vector<char> > > visited;


int calculate() {
	std::queue< std::tuple< std::vector<char>, std::vector<char>, std::vector<char>, int > >q;
	q.emplace(std::make_tuple(column[0], column[1], column[2],0));
	visited.insert(std::make_tuple(column[0], column[1], column[2]));

	while (!q.empty()) {
		std::vector<char> column_data[3];
		int num;
		std::tie(column_data[0], column_data[1], column_data[2], num) = q.front();
		q.pop();

		if (std::count(column_data[0].begin(), column_data[0].end(), 'A') == column_data[0].size() || column_data[0].size() == 0) {
			if (std::count(column_data[1].begin(), column_data[1].end(), 'B') == column_data[1].size() || column_data[1].size() == 0) {
				if (std::count(column_data[2].begin(), column_data[2].end(), 'C') == column_data[2].size() || column_data[2].size() == 0) {
					return num;
				}
			}
		}


		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (i == j || column_data[i].size() == 0) continue;
				std::vector<char> n_column_data[3];
				for (int k = 0; k < 3; k++) {
					n_column_data[k] = column_data[k];
				}
				char move_hanoi = n_column_data[i].back();
				n_column_data[i].pop_back();
				n_column_data[j].emplace_back(move_hanoi);
				if (visited.find(std::make_tuple(n_column_data[0], n_column_data[1], n_column_data[2])) == visited.end() )  {
					q.emplace(std::make_tuple(n_column_data[0], n_column_data[1], n_column_data[2], num + 1));
					visited.insert(std::make_tuple(n_column_data[0], n_column_data[1], column_data[2]));
				}
			}
		}
	}
}

int main() {
	int size[3];
	for (int i = 0; i < 3; i++) {
		scanf("%d", &size[i]);
		column[i].assign(size[i], 0);
		for (int j = 0; j < size[i]; j++) {
			scanf(" %1c", &column[i][j]);
		}
	}
	printf("%d", calculate());
}
