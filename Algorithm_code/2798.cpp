#include <iostream>
#include <algorithm>
#include "math.h"
#include "malloc.h"
using namespace std;





int calculate_memory(int n){
	int value=0;
	value=(n)*(n-1)*(n-2)/6;
	return value;
}


int sort_algorithm(int n, int m,int *v){
	//printf("n: %d",n);
	int *allocate_array=(int*)malloc(sizeof(int)*calculate_memory(n));
	//printf("sizeof allocate_array ÈÄ : %d\n",_msize(allocate_array));
	int stack=0;
	int sum=0;
	int max=0;
	
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			for(int k=j+1;k<n;k++){
				allocate_array[stack++]=v[i]+v[j]+v[k];
			
			}
		}
	}
	sort(allocate_array,allocate_array+stack);
	
	for(int i=0;i<stack;i++){
		if((allocate_array[i]<=m)&&(allocate_array[i]>max)){
			max=allocate_array[i];
		}
	}

	free(allocate_array);
	return max;
}



int main(){
	int n=0;
	int m=0;
	int stack=0;
	scanf("%d %d",&n,&m);
	int *v=(int*)malloc(sizeof(int)*n);
	
	for(int i=0 ;i<n; i++){
		scanf("%d",&v[i]);
	}
	
	printf("%d",sort_algorithm(n,m,v));
	
	
}
