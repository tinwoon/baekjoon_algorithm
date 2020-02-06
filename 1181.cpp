#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;



//일련의 데이터를 모두 넣고
//데이터를 사전순으로 정렬한 후
//데이터를 길이별로 출력할 수 있도록 하며 도중 이전데이터와 일치하는지를 비교  
int main(){
	int num=0;
	string tmp_data;
	int data_length=0;
	string prev_string="";
	vector<string> v;
	vector<string> data;
	scanf("%d",&num);
	
	
	for(int i=0;i<num;i++){
		cin>>tmp_data;
		data.push_back(tmp_data);
		if(data_length<tmp_data.length()) data_length=tmp_data.length();
	}
	
	sort(data.begin(),data.end());
	for(int i=1;i<data_length+1;i++){
		for(int j=0;j<data.size();j++){
			if(data[j].length()==i){
				if(data[j]==prev_string) continue;
				printf("%s\n",data[j].c_str());
				prev_string=data[j];
			}
			
		}
	}
	
} 
