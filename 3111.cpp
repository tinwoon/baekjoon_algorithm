#pragma warning (disable : 4996)
#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
#include <string>
#include <stack>

//���� 3111 �˿� ����
// ���� Ǯ�� ����� �Ʒ��� ���� �����ؾ��� �� => ��� �����ϴ��� �Ϻ� Ȱ���ؼ� �Ʒ��ڵ� �ϴ� �����ؾ���
// 1.ù��°�� store_front���� A�� �� ������ ���ڰ� ���� �� ���� �ְ�(3�����ÿ��� banana�� a), store_back���� ������ T ��� �ֱ� (�� �ʱ� �ʱ�ȭ)
// 2.dequeue�� store_front�� A�� �� ù��° ���ڰ� ���ö����� push_front�ϱ�
// 3.�� ù��° ���ڰ� �������� ���� A�� ��ġ�ϴ��� deququ�� �պ��� Ȯ���غ���(�ϳ� �¾����� dequeue���� ������Ű��, �ٽ� �ݺ��ؼ� �ȸ��� �� ����)
// 4.�ȸ¾����� 3���� �ٽ� �ݺ�(store_front�� empty�� �� ����)
// 5.stack_front�� empty�� ������, �ݴ�� dequeue�� store_back���� A�� �� ������ ���ڰ� ���Ë����� push_back�ϱ�.
// 6.�� ������ ���ڰ� �������� ���� A�� ��ġ�ϴ��� dequeue�� �ں��� Ȯ�� (�ϳ� ������ dequeue���� ������Ű��, �ٽ� �ݺ��ؼ� �ȸ��� ������)
// 7. �ȸ¾����� ���� 5�� �ݺ�(store_back�� empty�ϋ� ����)
// 8.��� �������� dequeue ����Ʈ�ϸ� �ȴ�.

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
			//���� �κ��� ������ ��
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
			//���� �κ��� ������ ��
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