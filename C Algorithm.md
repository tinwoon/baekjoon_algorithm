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

