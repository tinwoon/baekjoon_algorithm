#include <iostream>
#include <algorithm>
#include <vector>



//cmp에 return 값을 주지 않았을때 sort하는 방식이 return true;랑 같거나 return false;랑
//아니면 반환값이 없을때를 따로 정의하여 처리하는지 궁금.
//또 v.인자 ex)v.first가 어떤 걸 의미하는지 인덱스 값을 의미하는건지 인덱스가 가리키는 값을 의미하는지 모르겠음
using namespace std;


bool cmp(pair<int, string> a, pair<int, string> b){
	if(a.first<b.first){
		return true;
	}
	else return false;
}



int main(){
	int num=0;
	scanf("%d",&num);
	vector< pair<int,string> > v;
	
	v.resize(num);
	for(int i=0;i<num;i++){
		cin>>v[i].first>>v[i].second;
	}
	
	sort(v.begin(),v.end(),cmp);
	
	for(int i=0;i<v.size();i++){
		printf("%d %s\n",v[i].first,v[i].second.c_str());
	}
} 
