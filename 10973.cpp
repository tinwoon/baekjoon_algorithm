#include <iostream>
#include <algorithm>
#include <vector>

std::vector<int> value;

//std �����Լ� Ȱ��

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int data;
		scanf("%d", &data);
		value.push_back(data);
	}

	if (std::next_permutation(value.begin(), value.end())) {
		for (int i = 0; i < n; i++) {
			printf("%d ", value[i]);
		}
	}
	else printf("-1");
	

	

}
