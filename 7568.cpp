#include <iostream>

#include "malloc.h"
using namespace std;


//간단함
//몸무게 배열과, 키 배열과, 등수배열을 동적할당한 다음
//각각읇 비교해서 몸무게와 키가 자기자신보다 높으면 등수를 1씩 올리면 됨. 
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
