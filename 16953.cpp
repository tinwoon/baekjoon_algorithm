#pragma warning (disable : 4996)
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

//16953 A -> B ����
//bfs ���ؼ� �����ϰ� Ǯ �� �ִ� �����̴�.

typedef long long ll;

ll A, B;


ll calculate() {
	std::queue< std::pair<ll, ll> > q;
	q.emplace(std::make_pair(A, 0));

	while (!q.empty()) {
		auto front = q.front();
		q.pop();

		if (front.first == B) return front.second + 1;

		if (front.first * 2 <= B) {
			q.push(std::make_pair(front.first * 2, front.second + 1));
		}
		if ((front.first * 10) + 1 <= B) {
			q.push(std::make_pair(front.first * 10 + 1, front.second + 1));
		}
	}

	return -1;
}

int main() {
	scanf("%lld %lld", &A, &B);
	printf("%lld", calculate());

}