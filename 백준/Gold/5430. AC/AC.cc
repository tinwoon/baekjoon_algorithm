#pragma warning (disable : 4996)
#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
#include <string>

int T, n;
std::string p;
std::string arr_s;
std::deque<int> arr;

void convert() {
	int start = 1, end = 0;
	while (1) {
		end = arr_s.find(',', start);
		if (end == -1) {
			if(arr_s.size() != 2) arr.emplace_back(std::stoi(arr_s.substr(start, arr_s.size() - start)));
			break;
		}
		arr.emplace_back(std::stoi(arr_s.substr(start, end - start)));
		start = end + 1;
	}
}

std::string calculate() {
	std::string ret = "[";
	bool r_f = false;
	for (int k = 0; k < p.size(); k++) {
		if (p[k] == 'R') {
			r_f = !r_f;
		}
		else if (p[k] == 'D') {
			if (arr.size() == 0) return "error";
			if (!r_f) arr.pop_front();
			else arr.pop_back();
		}
	}

	if (arr.size()) {
		for (int k = (!r_f ? 0 : (arr.size() - 1)); !r_f ? (k < arr.size()) : (k >= 0); !r_f ? k++ : k--) {
			ret += std::to_string(arr[k]);
			ret += ',';
		}
		ret[ret.size() - 1] = ']';
	}
	else {
		ret = "[]";
	}

	return ret;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> T;

	while (T--) {
		arr.clear();
		std::cin >> p;
		std::cin >> n;
		std::cin >> arr_s;
		convert();
		std::cout << calculate() << std::endl;
	}
}