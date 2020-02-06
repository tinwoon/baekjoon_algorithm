#include <iostream>
#include <algorithm>

using namespace std;


//have_666을 통해 이 수가 666이 들어가는지 확 인  
//문제자체의 난이도 보다 효율적이고 깔끔한 알고리즘이 있다는 것을
//알게 됨.  근데 깔끔하게 짜는게 많이 한다고 가능한가...
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
