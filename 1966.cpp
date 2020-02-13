#include <iostream>
#include <queue>



int main() {
	std::priority_queue< std::vector<int> >pq;
	int num = 0;
	scanf("%d", &num);

	for (int i = 0; i < num; i++) {
		int question = 0;
		int position = 0;
		int stack = 1;
		std::vector<int> priority;
		scanf("%d %d", &question, &position);

		for (int j = 0; j < question; j++) {
			int tmp;
			scanf("%d", &tmp);
			priority.push_back(tmp);
			priority.push_back(j);
			pq.push(priority);
			priority.clear();
		}

		for (int j = 0; j < question; j++) {
			if (pq.top()[1] == position-1) {
				printf("%d\n", stack);
				break;
			}
			else {
				pq.pop();
				stack++;
			}
		}
		



	}
	
	
}
