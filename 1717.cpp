#include <iostream>
#include <vector>

//1717 ������ ǥ������
//union find(�и� ����)���� �� �̻� �� ���ϵ� �ƴϴ�. 
//�ش� ������ �ܿ�°� ���� ���� ���ϴ�.
//Ư�� parent[value] = get_parent(parent[value]) ������ �߿��ѵ�
//�ش� ������ �ܼ��� return get_parent(parent[value])�θ� ������ �Ѵٸ� N�� ����� ���� ã�� �� Ÿ��Ÿ�� �ö󰡴� ������ �ݺ��ؾ��Ѵ�.
//������ parent[value]�� N�� ����� root�� �ѹ� ��ͷ� ã�Ҵٸ� �� ���ĺ��� N�� ����� root�� ã�ƾ� �� ��쿣 O(1)�� ó���� �翬�� �����ϴ�. 

int N, M;
std::vector<int> parent;


int get_parent(int value) {
	if (parent[value] == value) return value;
	else return parent[value] = get_parent(parent[value]);
}

bool find(int a, int b) {
	a = get_parent(a);
	b = get_parent(b);
	if (a == b) return true;
	else return false;
}

void union_n(int a, int b) {
	a = get_parent(a);
	b = get_parent(b);
	if (a < b) parent[b] = a;
	else parent[a] = b;
}

int main() {
	scanf("%d %d", &N, &M);
	parent.assign(N + 1, 0);
	for (int k = 0; k < parent.size(); k++) {
		parent[k] = k;
	}
	for (int k = 0; k < M; k++) {
		int cmd, a, b;
		scanf("%d %d %d", &cmd, &a, &b);
		if (cmd == 0) {
			union_n(a, b);
		}
		else if (find(a, b)) printf("YES\n");
		else printf("NO\n");
	}
}
