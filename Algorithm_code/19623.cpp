#pragma warning (disable : 4996)
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <limits.h>
#include <numeric>
#include <math.h>

//19623 회의실 문제 4
//굉장히 까다로운 문제
//하지만 dp푸는 법의 기초는 무조건 다음과 같은 순서로 이루어진다는 교훈을 얻을 수 있었다.
//무조건 dp없이 풀었을 때 어떤 거를  메모리제이션할지를 결정하면 된다.
//예를 들어서 회의실 배정문제를 그냥 푼다면 당연히 브루트 포스로 모든 회의실에 대해 해당 회의실을 쓸거니? 안 쓸거니? 로 구분할 수 있다.
//이제 여기서 더 생각해보면 0~10번의 회의실이 있을 때 0번 회의실을 썼다면 1번 회의실은 0번 회의실부터 1번을 쓸 수 있는지 조사해서 값을 구하면 된다.
//이걸 반복하면 n-1번 회의실까지의 최댓값을 알면 거기다가 n번 회의실을 쓰면 또 최댓값이 된다.
//이런식으로 맨 처음 dp를 처음부터 쓰지 않는다면 어떻게 풀 수 있을지를 생각한다음 그렇게 풀었을 때 dp로 최적화 할 수 있는게 무엇인지 생각하면 된다. 

//끝난시간, 시작시간, 사람들
std::vector< std::tuple<int, int, int> > data;
int N;

//끝난시간, 이제까지 사람들
std::vector< std::pair<int, int> > dp;

bool cmp(const std::pair<int, int>& a, const std::pair<int, int>& b) {
	return a.first < b.first;
}

void calculate() {
	dp.emplace_back(std::make_pair(0, 0));
	for (int k = 0; k < data.size(); k++) {
		auto front = data[k];
		int p_finish, p_start, p_people;
		std::tie(p_finish, p_start, p_people) = front;

		auto index = std::lower_bound(dp.begin(), dp.end(), std::make_pair(p_start, 0), cmp) - 1;
		int max_people = std::max(p_people + index->second, dp.back().second);
		dp.emplace_back(std::make_pair(p_finish, max_people));
	}
	printf("%d", dp.back().second);
}

int main() {
	scanf("%d", &N);
	for (int k = 0; k < N; k++) {
		int start, finish, people;
		scanf("%d %d %d", &start, &finish, &people);
		data.emplace_back(std::make_tuple(finish, start, people));
	}
	std::sort(data.begin(), data.end());
	calculate();
}
