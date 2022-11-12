#pragma warning (disable : 4996)
#include <iostream>
#include <vector>

//1412 �Ϲ����� ����
//������ ���� �����ϴٴ� �ǹ̴� �ش� ������ ���ؼ� ����Ŭ�� ���������� ���� �� ������ �ǹ�
//�̴� �ش� ������ �����ص� �ȴٴ� �ǹ̿� �����ϴ�.(�ܹ��� ������ ������ָ� �ȴٴ� �ǹ�)


int N;
bool ans;

std::vector< std::vector<bool> > map;
std::vector<bool> visited;
std::vector<bool> finished;

void calculate(int node) {
	visited[node] = true;

	for (int k = 0; k < N; k++) {
		if (map[node][k] && !visited[k]) calculate(k);
		else if (map[node][k] && !finished[k]) ans = true;
	}

	finished[node] = true;
}

int main() {
	scanf("%d", &N);
	map.assign(N, std::vector<bool>(N, false));
	visited.assign(N, false);
	finished.assign(N, false);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			char v;
			scanf(" %1c", &v);
			if (v == 'Y') {
				if (map[j][i] == false) map[i][j] = true;
				else map[j][i] = false;
			}
		}
	}

	for (int node = 0; node < N; node++) {
		if (ans) break;
		if (!visited[node]) calculate(node);
	}

	printf("%s\n", ans ? "NO" : "YES");

}
