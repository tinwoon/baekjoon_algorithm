#include <iostream>
#include <vector>
#include <queue>
#include <string>

//https://www.acmicpc.net/problem/8111
//어디서 왔는지
std::vector<int> from;
//나머지의 값이 얼마인지
std::vector<int> div_value;
//몇번째 자리수 인지
std::vector<int> how_digit;


//이 코드는 이해도 해야하지만 싹다 외우는게 중요할 듯함.
std::string bfs(int n) {
	std::queue<int> q;
	q.push(1%n);
	how_digit[1 % n] = 1;
	from[1 % n] = 1;
	div_value[1 % n] = 1%n;
	std::string ans = "";

	while (!q.empty()) {
		auto front = q.front();
		q.pop();
		for (int i = 0; i <= 1; i++) {
			int next = ((front * 10) % n + i) % n;
			if (div_value[next] == -1) {
				div_value[next] = front;
				from[next] = i;
				how_digit[next] = how_digit[front] + 1;
				q.push(next);
			}
		}
	}
	if (div_value[0] == -1) {
		ans = "BRAK";
	}
	else {
		int previous = 0;
		for (int i = 0; i < how_digit[0]; i++) {
			ans.append(std::to_string(from[previous]));
			previous = div_value[previous];
		}
		std::reverse(ans.begin(),ans.end());
	}

	return ans;
}


int main() {
	int test_num;
	scanf("%d", &test_num);
	while (test_num--) {
		int n;
		scanf("%d", &n);
		from.assign(n,-1);
		div_value.assign(n, -1);
		how_digit.assign(n, -1);
		std::cout << bfs(n) << std::endl;
	}
}
