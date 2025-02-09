#pragma warning (disable : 4996)
#include <iostream>
#include <vector>
#include <string>

int T;
std::vector<int> store_char;
std::string ans;
std::vector< std::pair<int, int> > num_c[10] = { {{25,1}, {4, 1}, {17,1}, {14, 1}}, 
												{{14,1},{13,1},{4,1}}, 
												{{19,1},{22,1},{14,1}}, 
												{{19,1},{7,1},{17,1},{4,2}}, 
												{{5,1},{14,1},{20,1},{17,1}}, 
												{{5,1},{8,1},{21,1},{4,1}}, 
												{{18,1},{8,1},{23,1}}, 
												{{18,1},{4,2},{21,1},{13,1}}, 
												{{4,1},{8,1},{6,1},{7,1},{19,1}}, 
												{{13,1},{8,1},{13,1},{4,1}} };

bool nothing_remain() {
	for (int k = 0; k < 26; k++) {
		if (store_char[k]) return false;
	}
	return true;
}

void calculate(std::string number) {
	if (ans != "") return;

	bool find_n = false;

	for (int num = 0; num < 10; num++) {
		bool possible_f = true;
		for (int num_c_i = 0; num_c_i < num_c[num].size(); num_c_i++){
			if (store_char[num_c[num][num_c_i].first] < num_c[num][num_c_i].second) {
				possible_f = false;
				break;
			}
		}

		if (possible_f && ((int)number.size() < 6)) {
			for (int num_c_i = 0; num_c_i < num_c[num].size(); num_c_i++) {
				store_char[num_c[num][num_c_i].first] -= num_c[num][num_c_i].second;
			}
			calculate(number + std::to_string(num));
			find_n = true;
			for (int num_c_i = 0; num_c_i < num_c[num].size(); num_c_i++) {
				store_char[num_c[num][num_c_i].first] += num_c[num][num_c_i].second;
			}
		}
	}

	if (!find_n && nothing_remain()) ans = number;

	
}

int main() {
	std::cin >> T;
	int test_case = 1;
	
	while (T--) {
		std::string s;
		std::cin >> s;

		store_char.assign(26, 0);
		ans.clear();
		for (int k = 0; k < (int)s.size(); k++) {
			store_char[s[k] - 'A']++;
		}

		calculate("");
		std::cout << "Case #" << test_case++ << ": " << ans;
		if (T) std::cout << std::endl;
	}
	
}