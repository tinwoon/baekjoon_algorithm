#include <iostream>
#include <queue>

//1�� �Ǳ������� pop�Ѵ����� 
//1�� �Ǹ� pop�ϰ� ������.

int main() {
	std::queue<int> data;
	int num = 0;
	int where = 0;
	scanf("%d %d", &num,&where);
	for (int i = 1; i <= num; i++) {
		data.push(i);
	}

	printf("<");
	while (data.size() != 1) {
		for (int i = 0; i < where - 1; i++) {
			data.push(data.front());
			data.pop();
		}
		printf("%d, ", data.front());
		data.pop();
	}
	printf("%d>", data.front());
		
	
	return 0;
}
