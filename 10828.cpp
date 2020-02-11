#include <iostream>
#include <stack>
#include <string.h>

using namespace std;

int main() {
	int num = 0;
	scanf("%d", &num);

	stack<int> st;
	char str[6];
	int tmp;

	for (int i = 0; i < num; i++) {
		scanf("%s", str);

		if (strcmp(str,"push")==0) {
			
			scanf("%d", &tmp);
			st.push(tmp);

		}


		else if (strcmp(str, "pop") == 0) {

			if (!st.empty()) {
				printf("%d\n", st.top());
				st.pop();
			}
			else {
				printf("-1\n");
			}
		}


		else if (strcmp(str, "size") == 0) {
			printf("%d\n", st.size());
		}



		else if (strcmp(str, "empty") == 0) {

			if (st.empty()) {
				printf("1\n");
			}
			else {
				printf("0\n");
			}
		}



		else if (strcmp(str, "top") == 0) {
			if (!st.empty()) {
				printf("%d\n", st.top());
			}
			else {
				printf("-1\n");
			}
		}


	}

	return 0;

}
