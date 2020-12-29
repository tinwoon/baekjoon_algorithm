#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <tuple>
#include <map>

int S;
//std::map< std::pair<int,int>, bool > visited;
std::vector< std::vector<bool> >visited(2001, std::vector<bool>(2001,false));

void bfs(int clip, int emoticon, int num) {

	std::queue< std::tuple<int, int, int> >q;
	q.push(std::tuple<int,int,int>(clip,emoticon,num));
	visited[clip][emoticon] = true;

	while (!q.empty()) {

		auto front = q.front();
		q.pop();

		
		clip = std::get<0>(front);
		emoticon = std::get<1>(front);
		num = std::get<2>(front);

		if (emoticon == S) {
			printf("%d", num);
			break;
		}

		//복사
		if (!visited[emoticon][emoticon]) {
			q.push(std::tuple<int, int, int>(emoticon, emoticon, num + 1));
			visited[emoticon][emoticon] = true;
		}

		//붙여넣기
		if (emoticon + clip <= 2001) {
			if (!visited[clip][emoticon + clip]) {
				q.push(std::tuple<int, int, int>(clip, emoticon + clip, num + 1));
				visited[clip][emoticon + clip] = true;
			}
		}
		
		//삭제
		if (emoticon - 1 >= 0) {
			if (!visited[clip][emoticon - 1]) {
				q.push(std::tuple<int, int, int>(clip, emoticon-1, num + 1));
				visited[clip][emoticon - 1] = true;
			}
		}
		
		


	}
	
	
}


int main() {
	scanf("%d", &S);
	bfs(0,1,0);
}
