#include <iostream>
#include <vector>

int N, B, C;
std::vector<long long> test_room;

long long calculate() {
	long long rst = 0;
	for (auto it = test_room.begin(); it != test_room.end(); it++) {
		if (*it - B < 0) *it = 1;
		else if ((*it - B) % C >= 1) *it = ((*it - B) / C) + 2;
		else *it = ((*it - B) / C) + 1;
		rst += *it;
	}
	return rst;
}


int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		int num;
		scanf("%d", &num);
		test_room.emplace_back(num);
	}
	scanf("%d %d", &B, &C);
	printf("%lli", calculate());
}
