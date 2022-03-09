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



#### 2. C언어에서도 qsort를 제공해준다.(bsearch도 제공한다.)

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



#### 4. Const의 경우 포인터는 생성과 동시에 초기화 하지 않아도 된다. (컴파일 에러는 안나는데 접근 자체는)

```c
typedef struct Stag_ChannelType
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
}ChannelType;

int main() {
	
	uint8_t data = 10;
	uint8_t data2 = 20;
    //const int data3; => int형의 경우는 생성과 동시에 초기화가 일어나야하기 때문에 에러 발생한다.
    //아래의 포인터의 경우에는 생성과 동시에 초기화가 일어나지 않아도 되기 때문에 에러 발생하지 않는다.
    //근데 포인터라 초기화 안해주면 nullptr 참조할 수 밖에 없으므로 초기화는 const든 아니든 뒤에 해줘야한다.
	const uint8_t* value;

    //구조체 포인터의 경우에도 마찬가지이다.
	const ChannelType* LpChannel;

	LpChannel = &GaaChannel[0];

	value = &data;
	printf("%d\n", *value);
	value = &data2;
	printf("%d\n", *value);
    //const 타입을 값의 변경에 대해 차단했기 때문에 아래의 경우 오류 발생한다.
	*value = 19;

	
}
```



#### 5. Const의 고찰

```c
#pragma warning (disable : 4996)
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define INVALID 0xFF
#define CONF_TIMEOUT_COUNT 200
uint8_t g_data = 15;
uint8_t g_data_c = 16;

typedef struct Stag_ChannelType
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
}ChannelType;

const ChannelType GaaChannel[] = {
	{
		nullptr,
		&g_data,
		0,
		INVALID,
		0x01,
		0x01,
		0x00,
		INVALID,
		INVALID
	}
};



int main() {
    
	const ChannelType* LpChannel;
	uint8_t* LpAckTxPendingFlag;

	LpChannel = &GaaChannel[0];


	LpAckTxPendingFlag = LpChannel->pAckTxpendingFlag;

	*(LpChannel->pAckTxpendingFlag) = g_data;
    
    //출력 : 15
    printf("출력 : %d", *(LpChannel->pAckTxpendingFlag));

}
```

- `LpAckTxPendingFlag = LpChannel->pAckTxpendingFlag; *(LpChannel->pAckTxpendingFlag) = (uint8_t)0x01;`이 가능한가?

  > 가능하다.
  >
  > 코드를 보면 `const ChannelType* LpChannel;`의 경우 LpChannel의 내부 값을 변동할 수 없음만을 의미한다.
  >
  > 즉, `const int* Lpchannel`이라고 선언됐다면 Lpchannel의 값이 가리키는 값을 변경할 수 없다는 의미이므로,
  >
  > `const ChannelType* LpChannel;`의 경우는 Lpchannel-> ~ 등의 값을 변경할 수 없다는 의미이다.
  >
  > 
  >
  > 하지만 Lpchannel의 `uint8_t* pAckTxpendingFlag;`의 경우는 `const uint8_t* pAckTxpendingFlag`이 아니기 때문에 주소가 가리키는 값의 대입은 변화가 가능하다. 
  >
  > 
  >
  > 정리하면 `Lpchannel-> pAckTxpendingFlag = &g_data`는 불가능하지만, `*(Lpchannel-> pAckTxpendingFlag) = g_data`는 가능하다.



#### 6. 함수 포인터의 경우 Return type을 void로 변경할 수 있다.(https://m.blog.naver.com/PostView.naver?isHttpsRedirect=true&blogId=shup77&logNo=221648877396) => 이 블로그의 경우 정리 자체가 가로가 빠진게 많고 안되는게 맞는 것도 있다. 따라서 아래 코드가 완벽하게 잘 동작하는 코드이다.

```c
#include <stdio.h>
#include <stdlib.h>

void First(void);

int Second(int n);



int main(void) {

    void (*func1) (void);

    void (*func2) (int);



    func1 = (void (*) (void)) Second;

    printf("반환 : %d\n", ((int (*)(int)) func1)(123));


    func2 = ( void (*)(int) )First;

    func2(2);

}

void First() {
    printf("매개변수는 모르겠고, First는 출력합니다");
    return;
}

int Second(int n) {
    return n;
}
```



#### string 배열을 malloc으로 처리하고 싶을 때(1차만 처리하고 싶을때) 다음과 같이 처리할 수 있다.([혼자 연구하는 C/C++ by WinApi (soen.kr)](http://soen.kr/lecture/ccpp/cpp1/11-3-5.htm))

```c
void main()

{

     int i;

 

     char (*p)[4]=(char (*)[4])malloc(3*4*sizeof(char));

     strcpy(p[0],"dog");

     strcpy(p[1],"cow");

     strcpy(p[2],"cat");

     for (i=0;i<3;i++) puts(p[i]);

     free(p);

}

```



#### strcmp, strncmp 정리

> **▶strcmp, strncmp 설명**
>
> \- 매개변수로 들어온 **두개의 문자열을 비교 하여 문자열이 완전히 같다면 0을 반환하고, 다르면 음수 혹은 양수를 반환하는 함수**입니다.
>
> \- 여기서 -1, 1은 매개변수로 들어온 문자열들을 비교하다가 **다른 문자가 나왔을때 그 문자의 아스키 코드 값에 의해서 정해집니다.** 
>
> **(1) str1 < str2 인 경우에는 음수 반환**
>
> **(2) str1 > str2 인 경우에는 양수 반환**
>
> **(3) str1 == str2 인 경우에는 0을 반환 합니다.**
>
> 
>
> 출처: https://blockdmask.tistory.com/391 [개발자 지망생]

#### const void* casting 방법 (qsort를 통한 compare를 기반으로)

- `*(int*)a;` 이지 `(int*)*a`가 아니라는 것을 기억해야한다.

```c
#include <stdio.h>
#include <stdlib.h>

// 오름차순으로 정렬할 때 사용하는 비교함수
int static compare (const void* first, const void* second)
{
    if (*(int*)first > *(int*)second)
        return 1;
    else if (*(int*)first < *(int*)second)
        return -1;
    else
        return 0;
}

int main()
{
    int arr[] = {32, 11, 97, 42, 21, 70, 56, 67, 88, 100};
    int array_size = sizeof(arr) / sizeof(int);
    int i;

    // 정렬 전
    for (i = 0; i < array_size; i++) printf("%d ", arr[i]);
    printf("\n");

    qsort(arr, array_size, sizeof(int), compare);

    // 정렬 후
    for (i = 0; i < array_size; i++) printf("%d ", arr[i]);
    printf("\n");

    return 0;
}
```



#### Tree 할당 방법

```c
typedef struct _Tree_ {
    int value = -1;
	_Tree_* left = NULL;
	_Tree_* right = NULL;
}Tree;

Tree* root;

int main(){
    root = (Tree*)malloc(sizeof(Tree));
    Tree* node = (Tree*)malloc(sizeof(Tree));
    root->right = node;
}
```



#### malloc을 지역변수에 선언했다고 할당된 영역이 사라지는게 아니다.

- 물론 지역 변수 내에서 Tree* node = (Tree*)malloc(sizeof(Tree)); 했다면 node 포인터는 사라지는게 맞다.
- 하지만 malloc은 Tree에 대한 메모리를 할당하고 할당된 데이터의 주소를 반환하는 것이지 메모리가 free된게 아니다.
- 따라서 아래와 같이 선언했다면 똑같이 right의 데이터에 접근이 가능하다.
- 이 점을 꼭 기억해야한다.(이 내용을 모르면 미리 전역변수로 선언해서 초기화를 막아야한다 생각할 수 있다.)
- malloc을 통해 선언된 내용은 함수를 통해 할당된 내역이므로 블록을 해제해도 사라지진 않는다.

```c
typedef struct _Tree_ {
    int value = -1;
	_Tree_* left = NULL;
	_Tree_* right = NULL;
}Tree;

Tree* root;


int main(){
    root = (Tree*)malloc(sizeof(Tree));
    if(1){
    	Tree* node = (Tree*)malloc(sizeof(Tree));
    	node -> value = 15;
    	root->right = node;
    }
    printf("%d", root->right->value);
    //15가 출력된다.
}
```



#### 포인터로 할당된 내역을 배열로 접근이 가능하며, 타입에 따라 해당 길이가 늘어 날 수 있다.

```c
#pragma warning (disable : 4996)
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

uint32_t* metadata;

int main() {
	uint32_t md = 0xfff4fff0;
	metadata = &md;

	uint8_t* ptrMetadata = (uint8_t*)metadata;

	printf("ptr : %x\n", ptrMetadata[0]); //f0 출력
	printf("ptr : %x\n", ptrMetadata[1]); //ff 출력
	printf("ptr : %x\n", ptrMetadata[2]); //f4 출력
	printf("ptr : %x", ptrMetadata[3]); //ff 출력

}
```



#### 원칙적으로 구조체 선언 부분에서는 변수를 초기화할 수 없다!

- 따라서 아래 코드의 경우 nullptr로 초기화되지 않는다.

```c
typedef struct _Tree_ {
	_Tree_* left = nullptr;
	_Tree_* right = nullptr;
}Tree;
```

- 따라서 대부분의 경우 다음과 같이 함수로 만들어서 사용한다.

```c
Tree* init_node() {
	Tree* node = (Tree*)malloc(sizeof(Tree));
	node->right = node->left = nullptr;
	return node;
}
```

