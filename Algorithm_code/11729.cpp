// baekjoon.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>

using namespace std;


	unsigned int sum=0;
	vector<int> v_from;
	vector<int> v_to;






void Hanoi_start(int how_much, int from, int to, int tmp) {
		if (how_much == 1) {//만약 층이 하나짜리 라면 
			v_from.push_back(from);
			v_to.push_back(to);
			sum++;
		}
		else {
			Hanoi_start(how_much-1, from, tmp, to);
			v_from.push_back(from);
			v_to.push_back(to);
			sum++;
			Hanoi_start(how_much-1, tmp, to, from);
		}
	}



int main()
{

	unsigned int n;
	scanf("%d",&n);
	Hanoi_start(n, 1, 3, 2);
	printf("%d\n", sum);
	for(unsigned int i=0;i<v_from.size();i++){
		printf("%d %d\n",v_from[i],v_to[i]);
	}

}

// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.

