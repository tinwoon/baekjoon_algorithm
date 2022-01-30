#pragma warning (disable : 4996)
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <deque>
#include <stack>

//3111 �˿� ����
//�������� ��� ���� �ذ��� ����
// dq �ȿ� T�� ���ڸ� �ְ� stack_front�� �տ��� ���� ã��
// stack_back�� �ڿ��� ���� T�� ã���鼭 ������ �ذ��� 

std::string A;
std::string T;
std::deque<char> dq;

//�տ��� ã������ true return;
bool find_front(std::stack<char> &stack_front, std::stack<char> &stack_back) {
	std::stack<char> cnfrm;

	//dq�� ��������� �ȵȴ�.
	while (!dq.empty() || !stack_back.empty()) {
		//���� stack_front�� ���� �ִ´�.
		//���� dq�� ���� ������ dq���� ������
		if (!dq.empty()) {
			stack_front.emplace(dq.front());
			dq.pop_front();
		}
		//dq�� ���� ������ stack_back���� ���´�.
		else {
			stack_front.emplace(stack_back.top());
			stack_back.pop();
		}
		//A�� ������ ���ϱ� ���ؼ�
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

	//dq�� ��������� �ȵȴ�.
	while (!dq.empty() || !stack_front.empty()) {
		//���� stack_front�� ���� �ִ´�.
		//���� dq�� ���� ������ dq���� ������
		if (!dq.empty()) {
			stack_back.emplace(dq.back());
			dq.pop_back();
		}
		//dq�� ���� ������ stack_front���� ���´�.
		else {
			stack_back.emplace(stack_front.top());
			stack_front.pop();
		}
		//A�� ������ ���ϱ� ���ؼ�
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
