#include <iostream>
#include <vector>
#include <algorithm>


int N, S;
std::vector<int> value;
long long rst = 0;


//진짜 힘들었다 
//비트 연산자를 통해 구현
//부분 수열의 합을 두개로 나눔
//예를 들어 value의 값이 12345면
// first_subset에는 12에 대한 부분수열의 합
// second_subset에는 345에 대한 부분수열의 합을 구한다
// 그렇게 구한 first_subset과 second_subset의 부분 수열의 합으로 또 부분수열의 합을 구하면 된다.

//자꾸 틀린 이유가 있는데 con_first와 con_second의 값을 long long으로 안하고 int로 함
//first_subset과 second_subset의 값이 모두 같고 더한 값이 S랑 같다면
//최대 (1<<20)*(1<<20)까지 갈 수 있다는 점을 간과함.

long long calculate() {
	int first = N / 2;
	int second = N - first;
	//subset에는 부분집합들의 합이 모두 들어가있음.
	std::vector<int> subset;
	std::vector<int> first_subset;
	std::vector<int> second_subset;


	int cur = 0;
	for (int i = 0; i < (1 << first); i++) {
		for (int j = 0; j < first; j++) {
			if (i & (1 << j)) {
				cur += value[j];
			}
		}
		first_subset.push_back(cur);
		cur = 0;
	}
	for (int i = 0; i < (1 << second); i++) {
		for (int j = 0; j < second; j++) {
			if (i & (1 << j)) {
				cur += value[j + first];
			}
		}
		second_subset.push_back(cur);
		cur = 0;
	}
	sort(first_subset.begin(), first_subset.end());
	sort(second_subset.begin(), second_subset.end());
	std::reverse(second_subset.begin(), second_subset.end());

	int first_stack = 0;
	int second_stack = 0;

	while (1) {
		if (first_stack == first_subset.size() || second_stack == second_subset.size()) break;


		if (first_subset[first_stack] + second_subset[second_stack] == S) {
			long long con_first = 1;
			long long con_second = 1;
			while (first_stack + 1 < first_subset.size()) {
				if (first_subset[first_stack] == first_subset[first_stack + 1]) {
					con_first++;
					first_stack++;
				}
				else break;
			}
			while (second_stack + 1 < second_subset.size()) {
				if (second_subset[second_stack] == second_subset[second_stack + 1]) {
					con_second++;
					second_stack++;
				}
				else break;
			}


			rst += con_first * con_second;
			first_stack++;
			second_stack++;
		}
		else if (first_subset[first_stack] + second_subset[second_stack] < S) {
			first_stack++;
		}
		else {
			second_stack++;
		}
	}

	if (S == 0) rst -= 1;
	return rst;


}

int main() {
	scanf("%d %d", &N, &S);
	value.resize(N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &value[i]);
	}
	printf("%lli", calculate());
}
