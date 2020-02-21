#include <iostream>
#include <vector>
#include <algorithm>


std::vector< std::vector<int> >map(9,std::vector<int>(9));
std::vector< std::vector<int> >blank_data;

//백트래킹보다 그리드라 할 수 있을 듯
//dfs를 통해 구현했다는 의미가 가장 올바를 듯 함.

std::vector<int> Enable_num(std::vector<int> v) {//행, 열, 사각형 안에서 해당 좌표에 가능한 값
	std::vector<int> number = { 1,2,3,4,5,6,7,8,9 };
	for (int a = 0; a < 9; a++) {
		for (int b = 0; b < number.size(); b++) {
			if (v[a] == number[b]) {
				number.erase(number.begin()+b);
			}
		}
	}
	return number;
}


std::vector<int> Initialize_square(int i,int j) {//해당 좌표에서 3*3행렬안에서 가능한 수를 리턴

	std::vector<int> square;
	for (int a = (i / 3) * 3; a < ((i / 3) * 3) + 3; a++) {
		for (int b = (j / 3) * 3; b < ((j / 3) * 3) + 3; b++) {
			square.push_back(map[a][b]);
		}
	}
	
	return Enable_num(square);
}

std::vector<int> Initialize_row(int i, int j) {//해당 좌표의 행에 대해 가능한 수를 리턴
	std::vector<int> row;
	for (int k = 0; k < 9; k++) {
		row.push_back(map[i][k]);
	}
	
	return Enable_num(row);
}

std::vector<int> Initialize_column(int i, int j) {//해당 좌표의 열에 대해 가능한 수를 리턴
	std::vector<int> column;
	for (int k = 0; k < 9; k++) {
		column.push_back(map[k][j]);
	}
	
	return Enable_num(column);
}


void calculate(int i, int j,int stack) {

	//row, column, square에 대해서 해당 i,j좌표에 가능한 값을 저장해둠.
	std::vector<int> row = Initialize_row(i, j);
	std::vector<int> column = Initialize_column(i, j);
	std::vector<int> square = Initialize_square(i, j);
	std::vector<int> value(9);//여기에 해당 i,j좌표에 들어갈수 있는 수를 저장해둠
	std::vector<int>::iterator itr = std::set_intersection(row.begin(), row.end(), column.begin(), column.end(),value.begin());//교집합을 통해 row, column, square이 가능한 수를 value에 저장
	value.resize(itr - value.begin());
	itr = std::set_intersection(value.begin(), value.end(), square.begin(), square.end(), value.begin());
	value.resize(itr - value.begin());
	
	if (value.empty()) {
		return;
	 }

	for (int x = 0; x < value.size(); x++) {//value에 해당 i,j좌표에 가능한 수가 저장되어 있음으로 dfs를 통해 value값을 하나씩 뺴어 적용해 보면서 확인
		map[i][j] = value[x];

		if ((i == blank_data[blank_data.size() - 1][0]) && (j== blank_data[blank_data.size() - 1][1])) {
			for (int a = 0; a < 9; a++) {
				for (int b = 0; b < 9; b++) {
					printf("%d ", map[a][b]);
				}
				printf("\n");
			}exit(0);
		}

		std::vector< std::vector<int> >blank_data_x = blank_data;
		std::vector< std::vector<int> >map_x = map;

		calculate(blank_data[stack + 1][0], blank_data[stack + 1][1], stack + 1);
	}
	

}

int main() {
	
	std::vector<int> data;
	int stack=0;

	
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			scanf("%d", &map[i][j]);
			if (map[i][j] == 0) {
				data.push_back(i);
				data.push_back(j);
				blank_data.push_back(data);
				data.clear();
			}
		}
	}
	std::vector< std::vector<int> >blank_data_x = blank_data;
	std::vector< std::vector<int> >map_x = map;

	calculate(blank_data[stack][0], blank_data[stack][1],stack);
	
}
