#include <iostream>
#include <vector>
#include <set>

int N, K;
std::vector<int> degree;

bool calculate(int tmp) {
	
	for (int i = 0; i < degree.size(); i++) {
		for (int j = 0; j < degree.size(); j++) {
			int minus = (degree[i] - degree[j]) % 360;
			int plus = (degree[i] + degree[j]) % 360;
			if (!std::count(degree.begin(), degree.end(), std::abs(minus))) degree.push_back(std::abs(minus));
			if (!std::count(degree.begin(), degree.end(), std::abs(plus))) degree.push_back(std::abs(plus));
		}
	}

	if (std::count(degree.begin(), degree.end(), tmp)) return true;
	else return false;
}

int main() {
	scanf("%d %d", &N, &K);
	for (int i = 0; i < N; i++) {
		int tmp;
		scanf("%d", &tmp);
		degree.push_back(tmp);
	}
	
	for (int i = 0; i < K; i++) {
		int value;
		scanf("%d", &value);
		if (calculate(value)) printf("YES\n");
		else printf("NO\n");
	}

}
