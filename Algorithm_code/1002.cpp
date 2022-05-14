#include <iostream>
#include <vector>
#include <cmath>
#include <stdlib.h>

using namespace std;



//날코딩 할렐루야 
int calculate(float** v,int i){
	
	float distance=sqrt(pow(v[i][0]-v[i][3],2)+pow(v[i][1]-v[i][4],2));
	float minus=abs(v[i][2]-v[i][5]);
	float plus=v[i][2]+v[i][5];
	
	if((v[i][0]==v[i][3])&&(v[i][1]==v[i][4])){
		return minus==0?-1:0;
	}
	else if( (minus<distance)&&(distance<plus)) return 2;
	else if( (minus==distance) || (plus==distance) ) return 1;
	else if( (plus<distance)|| (distance<minus))  return 0;
	
	


}




int main(){
	int num=0;
	scanf("%d",&num);
	float** v =(float**)malloc(sizeof(float*)*num);
	for(int i=0;i<num;i++){
		v[i]=(float*)malloc(sizeof(float)*6);
	}
	int data[6]={0,};
	
	
	for(int i=0;i<num;i++){
		scanf("%f %f %f %f %f %f",&v[i][0],&v[i][1],&v[i][2],&v[i][3],&v[i][4],&v[i][5]);
	
	}
	
	for(int i=0;i<num;i++){
		printf("%d\n",calculate(v,i));
	}
	
	free(v);
	return 0;
}

