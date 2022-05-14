#include <iostream>
#include <queue>

//queue와ㅗdequeue를 이용한 문제
//로직 자체는 문제가 나와있는데로이다.
//position을 기준으로 해당 값이 i/2+1보다 크거나 같으면 3번 연산을
//아니라면 2번 연산을 하는게 최솟값이라는 것을 확인 할 수있다.
//따라서 초기조건으로 맨앞에 데이터가 우리가 찾는 데이터랑 일치하면 바로 1번연산을
//아니면 해당 값의 위치를 통해 2번 연산 또는 3번 연산을 수행한다. 
 
int main() {
	std::deque<int> dq;
	std::queue<int> position_data;

	int num = 0;
	int position_num = 0;
	int stack = 0;
	scanf("%d %d", &num, &position_num);

	for (int i = 0; i < position_num; i++) {
		int tmp;
		scanf("%d", &tmp);
		position_data.push(tmp);
	}

	for (int i = 0; i < num; i++) {
		dq.push_back(i + 1);
	}

	while (!position_data.empty()) {
		if (position_data.front() == dq.front()) {//1번연산 
			dq.pop_front();
			position_data.pop();
			continue;
		}
		for (int i = 0; i < dq.size(); i++) {
			if (position_data.front() == dq[i]) {//3번연산 
				if (i >= dq.size() / 2 + 1) {
					dq.push_front(dq.back());
					dq.pop_back();
					stack++;
				}
				else {//2번 연 산 
					dq.push_back(dq.front());
					dq.pop_front();
					stack++;
				}
			}
		}
		

	}

	printf("%d", stack);


}
