#include<stdio.h>



 // scanf�� ���ϰ��� ���������� �Է¹��� ������ �����̴�.
int main(void)
{
    int a = 0;
    int b = 0;
    
    while(scanf("%d %d", &a, &b) == 2)
    {
 	   printf("%d\n", a+b);
    }
}
