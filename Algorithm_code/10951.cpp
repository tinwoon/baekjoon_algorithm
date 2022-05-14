#include<stdio.h>



 // scanf의 리턴값은 성공적으로 입력받은 변수의 개수이다.
int main(void)
{
    int a = 0;
    int b = 0;
    
    while(scanf("%d %d", &a, &b) == 2)
    {
 	   printf("%d\n", a+b);
    }
}
