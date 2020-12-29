#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

std::vector<std::string>  data;
std::string overlap_remove;

//��¥ �������.
//overlap�� ���ؼ� �ߺ��� ������ ���ĺ��� ������ �����ϰ�
//overlap_remove�� �ߺ��� ������ ���ĺ��� �ִ´� (ABC�� ABGF�� ������ overlap_remove���� ABCGF�� ���ִ�)
//�� ���� prev_permutation�� ���� ������ ���� ����ؼ� ��ȭ�� v�� ���� value_mapping�� ���� ���ν����ش�.
//�׸��� ������ ����ϸ� ��.
int overlap_check() {
	std::vector< std::string > sort_value = data;
	std::string string_sum;
	for (auto itr = data.begin(); itr < data.end(); itr++) {
		string_sum += *itr;
	}
	sort(string_sum.begin(), string_sum.end());
	string_sum.erase(std::unique(string_sum.begin(), string_sum.end()), string_sum.end());
	overlap_remove = string_sum;
	return overlap_remove.size();
}

std::vector< std::pair<char, int> > value_mapping(std::vector<int> &v) {

	std::vector< std::pair<char, int> > mapping_value( overlap_remove.size() );
	
	for (int i = 0; i < overlap_remove.size(); i++) {
		mapping_value[i].first = overlap_remove[i];
		mapping_value[i].second = v[i];
	}
	return mapping_value;

}





void calculate(int num) {
	int max = 0;
	std::vector<int> v;
	std::vector < std::pair<char, int> > mapping_value;
	for (int i = 0; i < overlap_check(); i++) {
		v.push_back(9 - i);
	}


	do {
		mapping_value = value_mapping(v);
		int rst = 0;
		for (int i = 0; i < data.size(); i++) {
			for (int j = 0; j < data[i].size(); j++) {
				for (int k = 0; k < mapping_value.size(); k++) {
					if (data[i][j]== mapping_value[k].first) {
						rst += mapping_value[k].second * pow(10, data[i].size() - j - 1);
					}
				}
				
			} 
		}
		max = std::max(max, rst);

	} while(std::prev_permutation(v.begin(), v.end()));
	
	printf("%d", max);
}


int main() {
	int num = 0;
	scanf("%d", &num);
	for (int i = 0; i < num; i++) {
		std::string scanf_value;
		std::cin >> scanf_value;
		data.push_back(scanf_value);
	} 
	calculate(num);
	return 0;
}

