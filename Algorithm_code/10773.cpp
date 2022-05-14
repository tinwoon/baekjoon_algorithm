#include <iostream>
#include <stack>

//stack을 통해 구현
//
int main() {
	std::stack<int> v;
	int num;
	int tmp;
	int sum = 0;
	scanf("%d", &num);
	
	for (int i = 0; i < num; i++) {
		scanf("%d", &tmp);
		if (tmp != 0) {
			v.push(tmp);
		}
		else v.pop();
	}
	

	for (; !v.empty();) {
		sum += v.top();
		v.pop();
	}

 	printf("%d", sum);
}
