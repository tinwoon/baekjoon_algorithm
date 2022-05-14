#include <iostream>


//고딩때 순열과 조합을 이용 
int data[31][31];

void calculate(){
	for(int i=0;i<=30; i++){
		data[i][0]=1;
		data[i][i]=1;
		for(int j=1;j<=i-1;j++){
			data[i][j] = data[i-1][j-1]+data[i-1][j];
			
		}
		
	}
}

int main(){
	int num=0;
	scanf("%d", &num);
	calculate();
	while(num--){
		int a,b;
		scanf("%d %d", &a, &b);
		printf("%d\n", data[b][a]);
	}
	
	
}
