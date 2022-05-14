#include <iostream>
#include <algorithm>
#include <queue>
 
//백준 1655번 중간값을 구하는 것
//보통의 사람들이 생각하는 것처럼
//단순히 벡터를 넣을때마다 sort하는 방식은 1000000번의 정렬을 해야하기 때문에 시간초과가 발생한다.
//따라서 우선순위 큐를 통해 하나는 최댓값이 나오는 우선순위 큐 하나는 최솟값이 나오는 우선순위큐를 실행하여
//항상 최댓값이 나오는 우선순위큐의 top보다 큰 값은 최솟값이 나오는 우선순위큐에 넣어주면 top이 항상 중간 값이다.
//예를 들어 12345가 있다면 123까지는 최댓값이 나오는 우선순위큐 45까지는 최솟값이 나오는 우선순위 큐에 넣어주면 최댓값이 나오는 우선순위큐가 중간값임을 이용한다.
int main()
{
	int n;
	std::priority_queue<int, std::vector<int>, std::less<int> > max_first;
	std::priority_queue<int, std::vector<int>, std::greater<int> > min_first;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int tmp;
		scanf("%d", &tmp);
		if (max_first.size() == min_first.size()) {
			max_first.push(tmp);
		}
		else {
			min_first.push(tmp);
		}
		if (min_first.size() == 0);//min_first의 데이터가 비어 있으면 뒤의 조건문 "if (max_first.top() > min_first.top())"에 
		//min_first.top()가 빈 값을 참조하여 인덱스 오류가 남으로 else if문을 수행하지 않고 그냥 넘기도록 유도하기 위해 
		else if (max_first.top() > min_first.top()) {
			int tmp=max_first.top();
			max_first.pop();
			max_first.push(min_first.top());
			min_first.pop();
			min_first.push(tmp);
		}
		printf("%d\n", max_first.top());
	}
	return 0;
}
