#include <iostream>
#include <algorithm>

//����Ʈ, ����Ʈ, ���ĵ��� ���߿�
using namespace std;


int array[10001];



int main(){
	int num=0;
	int stack=0;
	scanf("%d",&num);
	for(int i=0;i<num;i++){
		scanf("%d",&stack);
		array[stack]++;
	}
	

	
	
	for(int i=1;i<10001;i++){
		if(array[i]!=0){
			for(int j=0;j<array[i];j++){
				printf("%d\n",i);
			}
		}
		
	}
	
	return 0;
}
