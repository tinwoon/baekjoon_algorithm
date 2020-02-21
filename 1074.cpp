#include <iostream>
#include <vector>
#include <cmath>


int n, r, c, stack;


//재귀와 사이즈를 이용하여 문제를 해결
//재귀적으로 순서는 알았으나 언제 기저함수를 발생시켜야할지를 굉장히 오래 고민
//사이즈를 통해 기저사례임을 구분할 수 있다는 것을 생각하지 못함
//추가적으로 데이터를 사용할 필요가 없다는 것을 알게됨(2차원 배열에 수들을 저장할 필요가 없음)
//또한 메모리 별로 계산 법을 숙지
//예를 들어 메모리 제한이 128MB라면 int형은 4바이트이고 1kb를 그냥 1000이라 가정하면 int형 변수를 
//128000000/4 = 32000000개를 생산할 수 있음
//즉 이문제는 n이 15이므로 2^15*2^15의 배열이 필요함
//계산하면 1073741824쯤 되므로 128MB를 초과. 즉 배열 선언을 할 수도 없고
//코드상에서도 좌표를 묻는게 아닌 좌표의 값을 묻으므로 스택을 통해 1씩 넣어두는 방식

int location(int size, int x, int y) {
	if (size==1) {
		stack++;
		if ((x == c + 1) && (y == r + 1)) {
			printf("%d\n", stack);

		}

		return 0;
		
	}
	else {
		location(size / 4, x - sqrt(size)/2, y - sqrt(size) / 2);
		location(size / 4, x, y - sqrt(size) / 2);
		location(size / 4, x - sqrt(size) / 2, y);
		location(size / 4, x, y);
	}
}


int main() {
	stack = 1;
	scanf("%d %d %d", &n, &r, &c);
	location(pow(pow(2,n),2), pow(2, n), pow(2, n));
}
