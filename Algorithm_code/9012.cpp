#include <iostream>
#include <stack>
#include <string.h>

//stack을 통해 구현
//char형을 통해 스트링을 비교할때 문자열이 아닌 char 배열하나
//즉 data[1] 이런 데이터 값은 문자이기 때문에 "이 아닌 '를 써야함
//예를들어 data[i]=="(" 은 불가능
//또한 data배열인덱스 각각은 문자열이 아니기 때문에 strcmp도 안됨
//예를 들어 strcmp(&data[i],'(')==0 안됨. data[i]=='('로 해야함
//또한 strlen(data)하면 이전에 배웠던 "\n"값이 들어가 
//데이터가 원하는 길이에 비해 1늘어날거라 생각하지만
//정말 우리가 원하는 데이터 길이임.
//예를들어 char data[51]에 "abc"를 넣고 strlen을 하면 길이가 4가아닌 3임
int right_VPS(char data[51]) {
	std::stack<int> v;
	for(int i = 0; i < strlen(data);i++) {
		
		if (data[i]=='(') {
			v.push(1);
		}
		else if (!v.empty()) {
			v.pop();
		}
		else return false;
			
	}
	if (v.empty()) return true;
	else return false;
}



int main() {
	int num = 0;
	scanf("%d", &num);
	for (int i = 0; i < num; i++) {
		char data[51];
		scanf("%s", data);
		printf("%s\n", right_VPS(data) == true ? "YES" : "NO");
		
	}



}
