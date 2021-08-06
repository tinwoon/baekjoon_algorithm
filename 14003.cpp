#include <iostream>
#include <vector>
#include <stack>
#include <limits.h>

//14003 가장 긴 증가하는 부분 수열 5
//굉장히 중요하다. 꼭 해당알고리즘을 기억할것
//lis 문제의 가장 효율적인 알고리즘으로
//k번째의 data에 해당하는 값이 lis 배열에서 몇번째 인덱스에 해당하는지를 적는다.
//예를 들면 10 20 10 30 20 50의 경우
//index 배열에는 1 2 1 3 2 4 순으로 저장된다.
//따라서 lis는 index의 반대 방향으로 4,3,2,1로 해당하는 값인 50 30 20 10을 역순으로 추출하면 된다.
//왜 역순으로 하고 출력하냐고 생각할 수 있는데
//-2 3 5 1 2 3 4의 index의 경우 1 2 3 1 2 3 4로 답이 -2 3 5 4라는 올바르지 않은 답안이 생성된다.
//따라서 뒤에서부터 찾아 역순으로 바꿔 출력해야한다.
long long N;
std::vector<long long> data;
std::vector<long long> lis;
std::vector<long long> index;
std::stack<long long> ans;

long long count = 0;

long long calculate() {
	lis.emplace_back(LLONG_MIN);

	for (int k = 0; k < N; k++) {
		if (lis.back() < data[k]) {
			count++;
			lis.emplace_back(data[k]);
			index[k] = (long long)lis.size() - 1;
		}
		else {
			auto itr = std::lower_bound(lis.begin(), lis.end(), data[k]);
			index[k] = (long long)std::distance(lis.begin(), itr);
			*itr = data[k];
		}
	}

	return count;
}

int main() {
	scanf("%lld", &N);
	data.assign(N, 0);
	index.assign(N, 0);
	for (int k = 0; k < N; k++) {
		scanf("%lld", &data[k]);
	}
	printf("%lld\n", calculate());

	int r_index = count;
	for (int k = N - 1; k >= 0; k--) {
		if (index[k] == r_index) {
			ans.emplace(data[k]);
			r_index--;
		}
	}

	while (!ans.empty()) {
		printf("%lld ", ans.top());
		ans.pop();
	}
}