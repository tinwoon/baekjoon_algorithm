#include <iostream>
#include <queue>

//이건 머 설명할 필요없어요
//시뮬레이터처럼 풀었음
//백준 11286
//pair를 통해 구현
//priority_queue가 맨처음의 값을 기준으로 정렬하기 때문에
//pair를 넣고 맨 앞을 abs한 값으로 둘째값을 기존의 값으로 한다음 넣기
//priority_queue는 first인덱스를 기준으로 나오게 됨으로 나온값의 second인덱스를 출력하면 됨
int main() {
	int n;
	scanf("%d", &n);
	std::priority_queue< std::pair<int,int>, std::vector< std::pair<int, int> >, std::greater< std::pair<int, int> > >data;
	while (n--) {
		int value;
		scanf("%d", &value);
		if (value != 0) {
			data.push({abs(value),value});
		}
		else if (data.size() != 0) {
			printf("%d\n", data.top().second);
			data.pop();
		}
		else printf("0\n");
	}
}
