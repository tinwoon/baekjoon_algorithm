#include <iostream>
#include "malloc.h"
#include <string>
#include <algorithm>
#include <vector>

using namespace std;


//string을 배열로 만들고 각각의 char형을 어떻게 접근하는지에 대한 
//기본문법의 필요성 다시 강조 

string chess[50];

string black[]={"BWBWBWBW"
				,"WBWBWBWB"
				,"BWBWBWBW"
				,"WBWBWBWB"
				,"BWBWBWBW"
				,"WBWBWBWB"
				,"BWBWBWBW"
				,"WBWBWBWB"};

string white[]={"WBWBWBWB"
				,"BWBWBWBW"
				,"WBWBWBWB"
				,"BWBWBWBW"
				,"WBWBWBWB"
				,"BWBWBWBW"
				,"WBWBWBWB"
				,"BWBWBWBW"};
				
int compare(string chess[],string black[],string white[],int height_distance,int width_distance){
	int b_value=0;
	int w_value=0;
	
	
	for(int i=0;i<8;i++){
		for(int j=0;j<8;j++){
			if(chess[i+height_distance][j+width_distance]!=black[i][j]){
				b_value++;
			}
			if(chess[i+height_distance][j+width_distance]!=white[i][j]){
				w_value++;

			}
		}
	}
	return b_value<w_value?b_value:w_value;
}


int main(){
	int width=0;
	int height=0;
	int min=64;
	int count=0;
	scanf("%d %d",&height,&width);
	for(int i=0;i<height;i++){
		cin>>chess[i];
	}
	
	for(int i=0;i<height-7;i++){
		for(int j=0;j<width-7;j++){
			int value=compare(chess,black,white,i,j);
			if(min>value) min=value;
		}
	}
	
	printf("%d", min);
	
	
	
	
	return 0;
}
