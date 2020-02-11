#include <iostream>
#include <queue>

//1이 되기전까지 pop한다음에 
//1이 되면 pop하고 종료함.

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
