#include <iostream>
#include <algorithm>
#include <vector>



//cmp�� return ���� ���� �ʾ����� sort�ϴ� ����� return true;�� ���ų� return false;��
//�ƴϸ� ��ȯ���� �������� ���� �����Ͽ� ó���ϴ��� �ñ�.
//�� v.���� ex)v.first�� � �� �ǹ��ϴ��� �ε��� ���� �ǹ��ϴ°��� �ε����� ����Ű�� ���� �ǹ��ϴ��� �𸣰���
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
