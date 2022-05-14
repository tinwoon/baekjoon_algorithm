#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

//4�ð����� ���ڵ���.
//�󵵰� ���� ���̽��� ���� ���� �˰��� �ʿ�
//������ ����� ���� ���� ���� �迭�� �и���.
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
		if(frq_plus[i]==stack){//���� ���� ���Դ� �󵵼��� ���ؼ� �Ȱ��� �󵵼���ŭ �Էµ� ���̸� ���Ϳ� Ǫ�� 
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
	int stack=0;//���� ���� �󵵼��� ���� ���ڰ� ��� ���Դ����� �� �� 
	
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
