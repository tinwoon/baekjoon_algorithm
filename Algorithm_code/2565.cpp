#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;



//dp문제이다.
//일단 맨 처음의 전기줄시작 루트순으로 이차원 배열을 정리한다
//1 3 2 4 6 10 9 7 같은 경우 1 2 3 4 6 7 9 10순의 이차원 배열로 정렬한 후
//lis알고리즘을 통해 구현한다.
//전기줄이 꼬이는 경우는 다음과 같다.
//첫번째로 순서가 전깃줄의 시작점의 인덱스의 값보다 후의 인덱스 값이 작으면 교차함으로
//전깃줄을 만들수 없다 예를들어 1인덱스의 값이 8인데 2의 인덱스가 2이면
//즉 후에 있는 인덱스의 숫자가 이전의 인덱스의 숫자보다 작으면 교차하기에 성립하지않는다
//이를 재귀적으로 최대한 많이 구하여 lis의 길이를 구한다음 없애야하는 최소개수이기 때문에 
//구한 답을 총 전깃줄의 개수에서 빼주면 없애야 하는 길이이다.
int calculate(int num, vector< vector<int> >data) {
	int max = 0;
	vector<int> dp;
	dp.resize(num+1);
	for (int i = 1; i <= num; i++)
	{
		int min = 0;
		for (int j = 0; j < i; j++) {
			if (data[i][1] > data[j][1]) {
				if (min < dp[j])
					min = dp[j];
			}
		}
		dp[i] = min + 1;
		if (max < dp[i])
			max = dp[i];
	}
	return max;
}


int main() {
	int num = 0;
	scanf("%d",&num);
	vector< vector<int> >data;
	vector<int> v;

	for (int i = 1; i <= num; i++) {
		int tmp_1, tmp_2;
		scanf("%d %d", &tmp_1, &tmp_2);
		v.push_back(tmp_1);
		v.push_back(tmp_2);
		data.push_back(v);
		v.clear();
	}
	v.push_back(0);
	v.push_back(0);
	data.insert(data.begin(),v);

	sort(data.begin(), data.end());

	printf("%d", num-calculate(num, data));


}
