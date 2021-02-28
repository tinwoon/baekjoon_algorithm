#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
#include <set>
#include <string>

long long s, t;
std::set<long long> visited;

//visited에 넣으면서, 연산을 확인하기
//단순히 q상태 값을 넣으면서 하면 됩니다.
std::string calculate() {
	std::queue < std::pair<long long, std::string> > q;
	q.emplace(std::make_pair(s, ""));
	visited.insert(s);

	while (!q.empty()) {
		auto front = q.front();
		q.pop();
		


		long long x = front.first;
		if (x == t) return front.second;


		if (visited.find(x * x) == visited.end() && x * x <=1000000000) {
			q.emplace(std::make_pair(x * x, front.second + '*'));
			visited.insert(x * x);
		}if (visited.find(x + x) == visited.end() && x + x <= 1000000000) {
			q.emplace(std::make_pair(x + x, front.second + '+'));
			visited.insert(x + x);
		}if(visited.find(0) == visited.end() ) {
			q.emplace(std::make_pair(0, front.second + '-'));
			visited.insert(0);
		}
		if (front.first != 0) {
			if (visited.find(1) == visited.end()) {
				q.emplace(std::make_pair(1, front.second + '/'));
				visited.insert(1);
			}
		}
	}

	return "-1";

}

int main() {
	scanf("%lli %lli", &s, &t);
	if (s == t) printf("0");
	else std::cout<< calculate();
}
