#include <iostream>

#include "malloc.h"
using namespace std;


//������
//������ �迭��, Ű �迭��, ����迭�� �����Ҵ��� ����
//������ ���ؼ� �����Կ� Ű�� �ڱ��ڽź��� ������ ����� 1�� �ø��� ��. 
int checked_grade(int* weight,int* height, int* grade, int num){
	
	for(int i=0;i<num;i++){
		for(int j=0;j<num;j++){
		if(i==j) continue;
			if( (weight[i]<weight[j]) && (height[i]<height[j]) ){
				grade[i]++;
			}
		}
	}
	
	for(int i=0;i<num;i++){
		printf("%d ",grade[i]);
	}

}




int main(){
	int num=0;
	scanf("%d",&num);
	int* weight=(int*)malloc(sizeof(int)*num);
	int* height=(int*)malloc(sizeof(int)*num);
	int* grade=(int*)malloc(sizeof(int)*num);
	 
	
	
	for(int i=0;i<num;i++){
		scanf("%d %d",&weight[i],&height[i]);
		grade[i]=1;
	}
	checked_grade(weight,height,grade,num);

}
