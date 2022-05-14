#include <iostream>
#include <queue>

//이건 머 설명할 필요없어요
//시뮬레이터처럼 풀었음
//백준 11279번 최대 힙
//자연수를 넣으면 데이터에 넣고
//0을 넣으면 이전에 넣었던 데이터 중 가장 높은 값을 뺌
int main() {
	int n;
	scanf("%d", &n);
	std::priority_queue< int, std::vector<int>, std::less<int> >data;
	while (n--) {
		int value;
		scanf("%d", &value);
		if (value > 0) {
			data.push(value);
		}
		else if (data.size() != 0) {
			printf("%d\n", data.top());
			data.pop();
		}
		else printf("0\n");
	}
	return 0;
}
