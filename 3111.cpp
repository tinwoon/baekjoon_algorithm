#pragma warning (disable : 4996)
#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
#include <string>
#include <stack>

//백준 3111 검열 문제
// 문제 풀이 방식을 아래와 같이 변경해야할 듯 => 모두 삭제하던가 일부 활용해서 아래코드 싹다 수정해야함
// 1.첫번째로 store_front에는 A의 맨 마지막 문자가 나올 때 까지 넣고(3번예시에선 banana의 a), store_back에는 나머지 T 모두 넣기 (맨 초기 초기화)
// 2.dequeue에 store_front에 A의 맨 첫번째 글자가 나올때까지 push_front하기
// 3.맨 첫번째 글자가 나왔으면 글자 A와 일치하는지 deququ의 앞부터 확인해보기(하나 맞았으면 dequeue에서 삭제시키고, 다시 반복해서 안맞을 때 까지)
// 4.안맞았으면 3번을 다시 반복(store_front가 empty일 때 까지)
// 5.stack_front가 empty가 됐으면, 반대로 dequeue에 store_back에서 A의 맨 마지막 글자가 나올떄까지 push_back하기.
// 6.맨 마지막 글자가 나왔으면 글자 A와 일치하는지 dequeue의 뒤부터 확인 (하나 맞으면 dequeue에서 삭제시키고, 다시 반복해서 안맞을 때까지)
// 7. 안맞았으면 위의 5번 반복(store_back이 empty일떄 까지)
// 8.모두 다했으면 dequeue 프린트하면 된다.

std::string T;
std::string A;

std::deque<char> dq;

bool is_equal_front(std::stack<char>& store_front) {

	int index_size = A.size();
	if (store_front.size() < index_size) return false;

	bool ret = true;
	std::stack<char> equal_A;

	for (int k = index_size - 1; k >= 0; k--) {
		if (store_front.top() == A[k]) {
			equal_A.emplace(A[k]);
			store_front.pop();
		}
		else {
			while (!equal_A.empty()) {
				store_front.emplace(equal_A.top());
				equal_A.pop();
			}
			ret = false;
			break;
		}
	}

	return ret;
}


bool is_equal_back(std::stack<char>& store_back) {

	int index_size = A.size();
	if (store_back.size() < index_size) return false;

	bool ret = true;
	std::stack<char> equal_A;

	for (int k = 0; k < index_size; k++) {
		if (store_back.top() == A[k]) {
			equal_A.emplace(A[k]);
			store_back.pop();
		}
		else {
			while (!equal_A.empty()) {
				store_back.emplace(equal_A.top());
				equal_A.pop();
			}
			ret = false;
			break;
		}
	}

	return ret;
}


void calculate() {

	std::stack<char> store_front;
	std::stack<char> store_back;
	bool dq_empty_flag = false;

	while (!dq_empty_flag) {

		do {
			if (dq.empty()) {
				dq_empty_flag = true;
				break;
			}
			//앞의 부분이 같은지 비교
			do {
				store_front.emplace(dq.front());
				dq.pop_front();
				if (dq.empty()) dq_empty_flag = true;
			} while (store_front.top() != A.back() && !dq_empty_flag);
		} while (!dq_empty_flag && !is_equal_front(store_front));


		do {
			if (dq.empty()) {
				dq_empty_flag = true;
				break;
			}
			//뒤의 부분이 같은지 비교
			do {
				store_back.emplace(dq.back());
				dq.pop_back();
				if (dq.empty()) dq_empty_flag = true;
			} while (store_back.top() != A.front() && !dq_empty_flag);
		} while (!dq_empty_flag && !is_equal_back(store_back));


	}

	std::deque<char> ans;

	while (!store_front.empty()) {
		ans.emplace_front(store_front.top());
		store_front.pop();
	}
	while (!store_back.empty()) {
		ans.emplace_back(store_back.top());
		store_back.pop();
	}

	while (!ans.empty()) {
		printf("%1c", ans.front());
		ans.pop_front();
	}
}

int main() {
	std::cin >> A;
	std::cin >> T;

	for (int k = 0; k < T.size(); k++) {
		dq.emplace_back(T[k]);
	}
	calculate();
}