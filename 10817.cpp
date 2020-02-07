#include <iostream>
#include <algorithm>

//Á¤·ÄÈÄ ¤¡¤¡
using namespace std;

int main() {
	int data[3];
	scanf("%d %d %d", &data[0], &data[1], &data[2]);
	sort(data, data+2);
	printf("%d", data[1]);
	return 0;
}
