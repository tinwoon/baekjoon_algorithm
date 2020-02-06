#include <iostream>
#include <algorithm>
#include <vector>
#include "math.h"
#include "malloc.h"
using namespace std;


//���ڸ� ������ �˰� ������ �ڸ����� vector�� �־���. 
//�� �ڸ����� ���ʿ��� ������ ���� �ʱ� ���ؼ� ����
//���� ��� ���ڸ� ���� 256�� ���ؼ� �����Ǵ� ������ ������ �ڸ����� 9+9+9 27������ �ִ� ����
//�̸� �̿��Ͽ� ������� ���̱� ����. 
int how_digit(int x){
	int stack=0;
	while(x!=0){
		x=x/10;
		stack++;
	}
	//printf("x�� �ڸ�����: %d, %d\n",x,stack);
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
