#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//이중벡터를 통해 구성
//좌표정렬1 그래도 구 성 
 
int main(){
	int num=0;
	scanf("%d",&num);
	vector< vector<int> > v1;
	vector<int> v2;
	int tmp_data[2]={0,};
	for(int i=0;i<num;i++){
		scanf("%d %d",&tmp_data[1],&tmp_data[0]);
		v2.push_back(tmp_data[0]);
		v2.push_back(tmp_data[1]);
		v1.push_back(v2);
		v2.pop_back();
		v2.pop_back();
	}
	
	sort(v1.begin(),v1.end());
	
	for(int i=0;i<v1.size();i++){
		printf("%d %d\n",v1[i][1],v1[i][0]);
	}
	
	
	
}
