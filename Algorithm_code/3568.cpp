//https://www.acmicpc.net/problem/3568

#include <iostream>
#include <vector>
#include <queue>
#include <string>

std::vector< std::string > data;

void calculate() {
	auto variable_notice = data.front();
	
	for (int i = 1; i < data.size(); i++) {
		std::cout << variable_notice;
		int dir = 1;
		std::string variable;
		std::string reverse_data;
		for (int j = 0; j < data[i].size(); j++) {
			if (!isalpha(data[i][j]) && dir) {
				std::cout << data[i][j];
			}
			else if (isalpha(data[i][j])) {
				variable.push_back(data[i][j]);
				dir = 0;
			}
			else {
				for (int k = data[i].size() - 2; k >= j; k--) {
					if (data[i][k] == '[') std::cout << ']';
					else if (data[i][k] == ']') std::cout << '[';
					else std::cout << data[i][k];
				}
				break;
			}
		}
		
		std::cout << ' ' << variable << ';' << std::endl;
	}
}

int main() {
	while (1) {
		std::string value;
		std::cin >> value;
		data.push_back(value);
		if (value.back() == ';') break; 
	}
	calculate();
}
