#include <iostream>
#include <vector>

int N;
std::vector<int> value;
int max = 0;

void calculate(int rst, std::vector<int> data) {
	auto tmp = data;
	if (rst > max) max = rst;

	for (int i = 1; i <= tmp.size() - 2; i++) {
		int energy = rst + tmp[i - 1] * tmp[i + 1];
		int erase_value = tmp[i];
		tmp.erase(tmp.begin() + i, tmp.begin() + i + 1);
		calculate(energy, tmp);
		tmp.insert(tmp.begin() + i, erase_value);
	}
}


int main() {
	scanf("%d", &N);
	value.assign(N,0);
	for (int i = 0; i < N; i++) {
		scanf("%d", &value[i]);
	}
	calculate(0, value);
	printf("%d", max);
}
