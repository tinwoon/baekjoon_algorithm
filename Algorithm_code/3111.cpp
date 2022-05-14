#pragma warning (disable : 4996)
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <deque>
#include <stack>

//3111 검열 문제
//일주일의 고민 끝에 해결한 문제
// dq 안에 T의 문자를 넣고 stack_front에 앞에서 부터 찾고
// stack_back에 뒤에서 부터 T를 찾으면서 문제를 해결함 

std::string A;
std::string T;
std::deque<char> dq;

//앞에서 찾았으면 true return;
bool find_front(std::stack<char> &stack_front, std::stack<char> &stack_back) {
	std::stack<char> cnfrm;

	//dq가 비어있으면 안된다.
	while (!dq.empty() || !stack_back.empty()) {
		//먼저 stack_front에 값을 넣는다.
		//만약 dq에 값이 있으면 dq에서 빼오고
		if (!dq.empty()) {
			stack_front.emplace(dq.front());
			dq.pop_front();
		}
		//dq에 값이 없으면 stack_back에서 빼온다.
		else {
			stack_front.emplace(stack_back.top());
			stack_back.pop();
		}
		//A와 같은지 비교하기 위해서
		if (stack_front.size() >= A.size() && stack_front.top() == A.back()) {
			bool flag = true;
			for (int k = A.size() - 1; k >= 0; k--) {
				if (stack_front.top() == A[k]) {
					cnfrm.emplace(stack_front.top());
					stack_front.pop();
				}
				else {
					flag = false;
					while (!cnfrm.empty()) {
						stack_front.emplace(cnfrm.top());
						cnfrm.pop();
					}
					break;
				}
			}
			if (flag) {
				while (!cnfrm.empty()) cnfrm.pop();
				return true;
			}
		}
	}

	return false;
}

bool find_back(std::stack<char> &stack_back, std::stack<char> &stack_front) {
	std::stack<char> cnfrm;

	//dq가 비어있으면 안된다.
	while (!dq.empty() || !stack_front.empty()) {
		//먼저 stack_front에 값을 넣는다.
		//만약 dq에 값이 있으면 dq에서 빼오고
		if (!dq.empty()) {
			stack_back.emplace(dq.back());
			dq.pop_back();
		}
		//dq에 값이 없으면 stack_front에서 빼온다.
		else {
			stack_back.emplace(stack_front.top());
			stack_front.pop();
		}
		//A와 같은지 비교하기 위해서
		if (stack_back.size() >= A.size() && stack_back.top() == A.front()) {
			bool flag = true;
			for (int k = 0; k < A.size(); k++) {
				if (stack_back.top() == A[k]) {
					cnfrm.emplace(stack_back.top());
					stack_back.pop();
				}
				else {
					flag = false;
					while (!cnfrm.empty()) {
						stack_back.emplace(cnfrm.top());
						cnfrm.pop();
					}
					break;
				}
			}
			if (flag) {
				while (!cnfrm.empty()) cnfrm.pop();
				return true;
			}
		}
	}

	return false;
}

void calculate() {
	std::stack<char> stack_front;
	std::stack<char> stack_back;

	while (1) {
		if (!find_front(stack_front, stack_back)) break;
		if (!find_back(stack_back, stack_front)) break;
	}
	
	while (!stack_front.empty()) {
		dq.emplace_front(stack_front.top());
		stack_front.pop();
	}
	while (!stack_back.empty()) {
		dq.emplace_back(stack_back.top());
		stack_back.pop();
	}
}

int main() {
	std::cin >> A;
	std::cin >> T;
	
	for (int k = 0; k < T.size(); k++) {
		dq.emplace_back(T[k]);
	}
	calculate();
	while (!dq.empty()) {
		printf("%1c", dq.front());
		dq.pop_front();
	}
}
