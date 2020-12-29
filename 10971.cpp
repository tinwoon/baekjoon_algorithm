#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>

std::vector< std::vector<int> >value;
std::vector<int> permutation;
int rst = 2000000000;
//std 내장함수 활용

int main() {
	int n = 0; 
	scanf("%d", &n);
	value.assign(n, std::vector<int>(n,0));
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &value[i][j]);
		}
	}
	
	for (int i = 0; i < n; i++) {
		permutation.push_back(i);
	}

	do {
		int sum = 0;

		for (int i = 0; i < n; i++) {

			if (value[permutation[i]][permutation[i + 1 == n ? 0 : i + 1]]) {
				sum += value[permutation[i]][permutation[i + 1 == n ? 0 : i + 1]];
			}
			else {
				sum = 1000000000;
				break;
			}
		}
		rst = std::min(sum, rst);
			
	} while(std::next_permutation(permutation.begin(), permutation.end()));

	printf("%d", rst);
}
