#pragma warning (disable : 4996)
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

//1994 등차수열 문제
//도무지 답이 안나와 답안 확인함.
//플레 5인 것도 납득이 안가고, 문제 자체도 더럽다(DP를 사용할 이유도 없음)
//최적화 방법을 lower_bound 쓰는 문제이면,
//애초에 각 배수 관계의 값을 기준으로 dp하는 방법이 조금 더 빠르지 않나 싶음
//ex. 2의 배수의 등차를 가지는 값을 기록한 상태에서 4의 배수의 등차를 dp로 알 수 있지 않나.

int N;
std::vector<int> data;

int calculate() {
	int ret = 1, now = 1;
	std::vector<int> ans;
	std::sort(data.begin(), data.end());
	ans.emplace_back(data[0]);

	//중복 제거
	for (int k = 1; k < N; k++) {
		if (data[k] == data[k - 1]) now++;
		else {
			ret = std::max(ret, now);
			now = 1;
			ans.emplace_back(data[k]);
		}
	}
	ret = std::max(ret, now);

	for (int i = 0; i < ans.size(); i++) {
		for (int j = i + 1; j < ans.size(); j++) {
			int v = 1;
			int diff = ans[j] - ans[i];
			auto itr = ans.begin() + i;
			while (1) {
				int f_v = *itr + diff;
				itr = std::lower_bound(itr, ans.end(), f_v);
				if (itr != ans.end() && *itr == f_v) v++;
				else break;
			}
			ret = std::max(ret, v);
		}
	}
	return ret;
}

int main() {
	scanf("%d", &N);

	for (int k = 0; k < N; k++) {
		int v;
		scanf("%d", &v);
		data.emplace_back(v);
	}
	printf("%d", calculate());

}