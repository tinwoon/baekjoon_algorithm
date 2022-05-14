#include <iostream>
#include <vector>

//1717 집합의 표현문제
//union find(분리 집합)문제 그 이상 그 이하도 아니다. 
//해당 구문은 외우는게 제일 좋을 듯하다.
//특히 parent[value] = get_parent(parent[value]) 구문은 중요한데
//해당 구문을 단순히 return get_parent(parent[value])로만 구성을 한다면 N번 노드의 값을 찾을 때 타고타고 올라가는 과정을 반복해야한다.
//하지만 parent[value]로 N번 노드의 root를 한번 재귀로 찾았다면 그 이후부터 N번 노드의 root를 찾아야 할 경우엔 O(1)에 처리가 당연히 가능하다. 

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
