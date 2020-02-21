#include <iostream>
#include <vector>
#include <algorithm>


std::vector< std::vector<int> >map(9,std::vector<int>(9));
std::vector< std::vector<int> >blank_data;

//��Ʈ��ŷ���� �׸���� �� �� ���� ��
//dfs�� ���� �����ߴٴ� �ǹ̰� ���� �ùٸ� �� ��.

std::vector<int> Enable_num(std::vector<int> v) {//��, ��, �簢�� �ȿ��� �ش� ��ǥ�� ������ ��
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


std::vector<int> Initialize_square(int i,int j) {//�ش� ��ǥ���� 3*3��ľȿ��� ������ ���� ����

	std::vector<int> square;
	for (int a = (i / 3) * 3; a < ((i / 3) * 3) + 3; a++) {
		for (int b = (j / 3) * 3; b < ((j / 3) * 3) + 3; b++) {
			square.push_back(map[a][b]);
		}
	}
	
	return Enable_num(square);
}

std::vector<int> Initialize_row(int i, int j) {//�ش� ��ǥ�� �࿡ ���� ������ ���� ����
	std::vector<int> row;
	for (int k = 0; k < 9; k++) {
		row.push_back(map[i][k]);
	}
	
	return Enable_num(row);
}

std::vector<int> Initialize_column(int i, int j) {//�ش� ��ǥ�� ���� ���� ������ ���� ����
	std::vector<int> column;
	for (int k = 0; k < 9; k++) {
		column.push_back(map[k][j]);
	}
	
	return Enable_num(column);
}


void calculate(int i, int j,int stack) {

	//row, column, square�� ���ؼ� �ش� i,j��ǥ�� ������ ���� �����ص�.
	std::vector<int> row = Initialize_row(i, j);
	std::vector<int> column = Initialize_column(i, j);
	std::vector<int> square = Initialize_square(i, j);
	std::vector<int> value(9);//���⿡ �ش� i,j��ǥ�� ���� �ִ� ���� �����ص�
	std::vector<int>::iterator itr = std::set_intersection(row.begin(), row.end(), column.begin(), column.end(),value.begin());//�������� ���� row, column, square�� ������ ���� value�� ����
	value.resize(itr - value.begin());
	itr = std::set_intersection(value.begin(), value.end(), square.begin(), square.end(), value.begin());
	value.resize(itr - value.begin());
	
	if (value.empty()) {
		return;
	 }

	for (int x = 0; x < value.size(); x++) {//value�� �ش� i,j��ǥ�� ������ ���� ����Ǿ� �������� dfs�� ���� value���� �ϳ��� ���� ������ ���鼭 Ȯ��
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
