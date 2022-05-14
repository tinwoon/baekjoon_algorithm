#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

//4시간동안 날코딩함.
//빈도가 높은 케이스에 대해 좋은 알고리즘 필요
//음수와 양수에 대한 값을 따로 배열로 분리함.
using namespace std;




int avg(int num,int* array){
	float data=0;
	for(int i=0;i<num;i++){
		data=data+array[i];
	}
	return round(data/num);
}




int center(int num,int* array){
	return array[num/2];
}


int second_find(int* frq_plus,int* frq_minus, int stack,int num){
	vector<int> v;
	
	for(int i=0;i<4001;i++){
		if(frq_plus[i]==stack){//가장 많이 나왔던 빈도수랑 비교해서 똑같은 빈도수만큼 입력된 값이면 벡터에 푸쉬 
			v.push_back(i);
		}
		if(frq_minus[i]==stack){
			v.push_back(i*(-1));
		}
		
	}
	sort(v.begin(),v.end());
	return v.size()==1?v[0]:v[1];
	
}


int frequency(int num,int* array){
	
	int frq_plus_array[4001]={0,};
	int frq_minus_array[4001]={0,};
	int stack=0;//가장 많은 빈도수를 가진 숫자가 몇번 나왔는지를 저 장 
	
	for(int i=0;i<num;i++){
		if(array[i]<0){
			frq_minus_array[abs(array[i])]++;
			if(frq_minus_array[abs(array[i])]>stack){
				stack=frq_minus_array[abs(array[i])];
			}
		}else{
			frq_plus_array[array[i]]++;
			if(frq_plus_array[array[i]]>stack){
				stack=frq_plus_array[array[i]];
			}
		}
		
	} 
	
	return second_find(frq_plus_array,frq_minus_array,stack,num);
	
}





int distance(int num,int* array){
	return array[num-1]-array[0];
}



int main(){
	int num=0;

	scanf("%d",&num);
	
	int* array=(int*)malloc(sizeof(int)*num);

	for(int i=0;i<num;i++){
		cin>>array[i];
	}
	

	sort(array,array+num);
	
	printf("%d\n",avg(num,array));
	printf("%d\n",center(num,array));
	printf("%d\n",frequency(num,array));
	printf("%d\n", distance(num,array));

	
	return 0;
	
	
}
