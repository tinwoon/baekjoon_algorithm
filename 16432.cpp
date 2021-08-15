#include <iostream>
#include <vector>
#include <algorithm>

//합이 0 문제
//해당 문제는 단순히 세용액처럼 이분탐색을 통해 풀 수 있는 내용이다.
//두개의 학생의 조합을 찾아서 더한후 그 해당 값과 같은 학생을 고르는 경우의 수를 계속 더해주면 되는 문제이다. 

int N;
std::vector<int> student;

long long calculate() {
	long long count = 0;
	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			int two_sum = student[i] + student[j];
			auto same_another = std::equal_range(student.begin() + (j + 1), student.end(), two_sum * -1);
			count += (long long)(same_another.second - same_another.first);
		}
	}
	return count;
}

int main() {
	scanf("%d", &N);
	student.assign(N, 0);
	for (int k = 0; k < N; k++) {
		scanf("%d", &student[k]);
	}
	std::sort(student.begin(), student.end());
	printf("%lld", calculate());
}
