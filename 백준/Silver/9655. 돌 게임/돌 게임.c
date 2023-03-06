#include <stdio.h>
#include <stdlib.h>

int N;

int main(){
    scanf("%d", &N);
    printf("%s", ((N % 2) == 1) ? "SK" : "CY");
}