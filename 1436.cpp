#include <iostream>
#include <algorithm>

using namespace std;


//have_666�� ���� �� ���� 666�� ������ Ȯ ��  
//������ü�� ���̵� ���� ȿ�����̰� ����� �˰����� �ִٴ� ����
//�˰� ��.  �ٵ� ����ϰ� ¥�°� ���� �Ѵٰ� �����Ѱ�...
bool have_666(int n){
	unsigned int value=n;
	int stack=0;
	if(n==0) return false;
	
	
	for(int i=0;i<3;i++){
		if(value%10==6){
			stack++;
		}
		value=value/10;
	}
		
	if(stack==3) return true;
	else return have_666(n/10);
	
	
}

int main(){
	int n=0;
	int count=0;
	unsigned int number=0;
	scanf("%d",&n);
	while(n!=count){
		number++;
		if(have_666(number)){
			count++;
		}
	}
	
	printf("%d",number);
}
