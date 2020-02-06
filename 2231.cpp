#include <iostream>
#include <algorithm>
#include <vector>
#include "math.h"
#include "malloc.h"
using namespace std;


//몇자리 수인지 알고 각각의 자리수를 vector에 넣어줌. 
//각 자리수에 불필요한 연산을 하지 않기 위해서 만듬
//예를 들어 세자리 수인 256에 대해서 생성되는 값들은 각각의 자리수인 9+9+9 27까지가 최대 범위
//이를 이용하여 계산방식을 줄이기 위함. 
int how_digit(int x){
	int stack=0;
	while(x!=0){
		x=x/10;
		stack++;
	}
	//printf("x와 자릿값은: %d, %d\n",x,stack);
	return stack;
}

int digit_sum(int x){
	int sum=0;
	int value=0;
	while(x!=0){
		value=x%10;
		sum=sum+value;
		x=x/10;
	}
	return sum;
}


int calculate(int n){
	int min=1000000;
	for(int i=n-(how_digit(n)*9);i<n;i++){
		//printf("i,n,digit_sum: %d, %d %d\n",i,n,digit_sum(i));
		if(((i+digit_sum(i))==n)&&(i<min)){
			//printf("i: %d\n",i);
			min=i;
			//printf("min: %d\n",min);
			
		}
	}
	if(min!=1000000){
		return min;
	}
	else return 0;
}



int main(){
	int x=0;
	vector<int> digit;
	
	scanf("%d",&x);
	printf("%d",calculate(x));
	
	return 0;
	
}
