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

//19623 ȸ�ǽ� ���� 4
//������ ��ٷο� ����
//������ dpǪ�� ���� ���ʴ� ������ ������ ���� ������ �̷�����ٴ� ������ ���� �� �־���.
//������ dp���� Ǯ���� �� � �Ÿ�  �޸����̼������� �����ϸ� �ȴ�.
//���� �� ȸ�ǽ� ���������� �׳� Ǭ�ٸ� �翬�� ���Ʈ ������ ��� ȸ�ǽǿ� ���� �ش� ȸ�ǽ��� ���Ŵ�? �� ���Ŵ�? �� ������ �� �ִ�.
//���� ���⼭ �� �����غ��� 0~10���� ȸ�ǽ��� ���� �� 0�� ȸ�ǽ��� ��ٸ� 1�� ȸ�ǽ��� 0�� ȸ�ǽǺ��� 1���� �� �� �ִ��� �����ؼ� ���� ���ϸ� �ȴ�.
//�̰� �ݺ��ϸ� n-1�� ȸ�ǽǱ����� �ִ��� �˸� �ű�ٰ� n�� ȸ�ǽ��� ���� �� �ִ��� �ȴ�.
//�̷������� �� ó�� dp�� ó������ ���� �ʴ´ٸ� ��� Ǯ �� �������� �����Ѵ��� �׷��� Ǯ���� �� dp�� ����ȭ �� �� �ִ°� �������� �����ϸ� �ȴ�. 

//�����ð�, ���۽ð�, �����
std::vector< std::tuple<int, int, int> > data;
int N;

//�����ð�, �������� �����
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
