#include <iostream>
#include <queue>

//queue�ͤ�dequeue�� �̿��� ����
//���� ��ü�� ������ �����ִµ����̴�.
//position�� �������� �ش� ���� i/2+1���� ũ�ų� ������ 3�� ������
//�ƴ϶�� 2�� ������ �ϴ°� �ּڰ��̶�� ���� Ȯ�� �� ���ִ�.
//���� �ʱ��������� �Ǿտ� �����Ͱ� �츮�� ã�� �����Ͷ� ��ġ�ϸ� �ٷ� 1��������
//�ƴϸ� �ش� ���� ��ġ�� ���� 2�� ���� �Ǵ� 3�� ������ �����Ѵ�. 
 
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
		if (position_data.front() == dq.front()) {//1������ 
			dq.pop_front();
			position_data.pop();
			continue;
		}
		for (int i = 0; i < dq.size(); i++) {
			if (position_data.front() == dq[i]) {//3������ 
				if (i >= dq.size() / 2 + 1) {
					dq.push_front(dq.back());
					dq.pop_back();
					stack++;
				}
				else {//2�� �� �� 
					dq.push_back(dq.front());
					dq.pop_front();
					stack++;
				}
			}
		}
		

	}

	printf("%d", stack);


}
