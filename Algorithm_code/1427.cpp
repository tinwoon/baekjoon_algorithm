#include <iostream>
#include <algorithm>


using namespace std;

int main(){
	string data;
	cin>>data;
	sort(data.begin(),data.end());
	reverse(data.begin(),data.end());
	cout<<data;
	return 0;
	
} 
