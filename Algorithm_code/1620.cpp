#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <string>

//백준 1620 나는야 포켓몬 마스터 이다솜
//어려운 내용은 없었으나 최적화를 고려하면 더 오래 걸릴 것으로 예측되는 문제
//"\n"이 std::endl보다 빠름

int N, M;
std::map<std::string, int> string_int;
std::vector<std::string> int_string;


int main() {
	std::cin.tie(NULL);
	std::ios_base::sync_with_stdio(false);

	std::string val;
	std::cin >> N >> M;

	for (int k = 0; k < N; k++) {
		std::cin >> val;
		string_int.emplace(std::make_pair(val, k + 1));
		int_string.emplace_back(val);
	}
	for (int k = 0; k < M; k++) {
		std::cin >> val;
		if (std::isalpha(val[0])) {
			std::cout << string_int[val] << "\n";
		}
		else std::cout << int_string[std::stoi(val) - 1] << "\n";
	}
}