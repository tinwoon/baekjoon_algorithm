//https://www.acmicpc.net/problem/14225
//시간이 다른 사람보다 4배 정도 더 걸리는데 다른 사람은 배열의 크기를
//bool c[20*100000+10]정도로 처음부터 만듬(뒤의 10은 혹시 초과할까봐)
//배열의 할당량과 메모리를 확인하고 풀면 차라리 정적으로 만들어 놓는게 빠를 수 도 있음.
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

int n;
std::vector<int> digit;

int calculate() {
	std::set<int> make_value;
	for (int i = 1; i < (1<<n); i++) {
		int value = 0;
		for (int j = 0; j < n; j++) {
			if (i & (1 << j)) value += digit[j];
		}
		make_value.insert(value);
	}

	
	int tmp = 1;
	for (auto itr = make_value.begin(); itr != make_value.end(); itr++) {
		if (*itr != tmp) {	
			return tmp;
		}
		else tmp++;
	}
	return make_value.size() + 1;

}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int tmp;
		scanf("%d", &tmp);
		digit.push_back(tmp);
	}
	printf("%d", calculate());
}

