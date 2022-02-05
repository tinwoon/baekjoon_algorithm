# [백준 알고리즘](https://www.acmicpc.net/)



#### 1. linked list를 동적 배열로 선언하거나, struct 구조를 동적 배열로 선언하고 싶으면 다음과 같이 정의하면 된다.[https://modoocode.com/100]

```c
#pragma warning (disable : 4996)
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef struct _NODE_ {
	int value = 0;
	_NODE_* right = nullptr;
	_NODE_* left = nullptr;
}NODE;

int n, m;

int main() {
	scanf("%d %d", &n, &m);
	NODE* node = (NODE*)malloc(n * sizeof(NODE));
    
    free(node);
}
```



#### 2. C언어에서도 qsort를 제공해준다.

```c
#include <stdio.h>
#include <stdlib.h>    // qsort 함수가 선언된 헤더 파일

int compare(const void *a, const void *b)    // 오름차순 비교 함수 구현
{
    int num1 = *(int *)a;    // void 포인터를 int 포인터로 변환한 뒤 역참조하여 값을 가져옴
    int num2 = *(int *)b;    // void 포인터를 int 포인터로 변환한 뒤 역참조하여 값을 가져옴

    if (num1 < num2)    // a가 b보다 작을 때는
        return -1;      // -1 반환
    
    if (num1 > num2)    // a가 b보다 클 때는
        return 1;       // 1 반환
    
    return 0;    // a와 b가 같을 때는 0 반환
}

int main()
{
    int numArr[10] = { 8, 4, 2, 5, 3, 7, 10, 1, 6, 9 };    // 정렬되지 않은 배열

    // 정렬할 배열, 요소 개수, 요소 크기, 비교 함수를 넣어줌
    qsort(numArr, sizeof(numArr) / sizeof(int), sizeof(int), compare);

    for (int i = 0; i < 10; i++)
    {
        printf("%d ", numArr[i]);    // 1 2 3 4 5 6 7 8 9 10
    }

    printf("\n");

    return 0;
}
```



#### 3. [scanf시 "%c"의 경우만 \n 버퍼처리 관리가 필요하다.][https://dojang.io/mod/page/view.php?id=638]



#### 4. Const의 경우 포인터는 생성과 동시에 초기화 하지 않아도 된다.

```c
typedef struct Stag_J1939Rm_ChannelType
{
	uint16_t* pAckTxTimeoutCounter;
	uint8_t* pAckTxpendingFlag;
	
	const uint8_t ddComMNtwrkHandleId;
	const uint16_t ddPduRackTxId;
	const uint8_t ucAckQueuesize;
	const uint8_t ucAckTxPendingMask;
	const uint8_t ucAckQueueInfoAccessIndex;
	const uint8_t ddAckTxPduId;
	const uint8_t ucAckTxPduIndex;
}J1939Rm_ChannelType;

int main() {
	
	uint8_t data = 10;
	uint8_t data2 = 20;
    //const int data3; => int형의 경우는 생성과 동시에 초기화가 일어나야하기 때문에 에러 발생한다.
    //아래의 포인터의 경우에는 생성과 동시에 초기화가 일어나지 않아도 되기 때문에 에러 발생하지 않는다.
	const uint8_t* value;

    //구조체 포인터의 경우에도 마찬가지이다.
	const J1939Rm_ChannelType* LpChannel;

	LpChannel = &J1939Rm_GaaChannel[0];

	value = &data;
	printf("%d\n", *value);
	value = &data2;
	printf("%d\n", *value);
    //const 타입을 값의 변경에 대해 차단했기 때문에 아래의 경우 오류 발생한다.
	*value = 19;

	
}
```

