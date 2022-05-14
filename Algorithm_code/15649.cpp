#include <iostream>
#include <vector>

using namespace std;

/*void back_tracking(vector<int> &v,vector<bool> &is_ok,int N,int M){
	v.clear();
	int cnt=0;
	for(int i=1;i<N+2;i++){
		if(cnt==M){
			break;
		}
		
		for(int j=0;j<M;j++){
			if(is_ok[j]!=true){
				v.push_back(i);
				is_ok[j]=true;
				cnt++;
				printf("j가 %d이고 i가 %d일때 cnt: %d\n ",j,i,cnt);
				break;
			}
			
		}
	}

	for(int i=0;i<v.size();i++){
		printf("%d ",v[i]);
	}
	
}







int main(){
	int N,M=0;
	scanf("%d %d",&N,&M);
	
	vector<int> v(M);
	vector<bool> is_ok(M,false);
	
	back_tracking(v,is_ok,N,M);
	
	
	
	
	
}*/

const int MAX = 8 + 1;

int N, M;
int arr[MAX];
bool visited[MAX];

void func(int cnt)
{
	if (cnt == M)
	{
		for (int i = 0; i < M; i++)
			cout << arr[i] << " ";
		cout << "\n";
		return;
	}

	for (int i = 1; i <= N; i++)
		if (!visited[i])
		{
			
			
			visited[i] = true;
			arr[cnt] = i;
			
	
			func(cnt + 1);
			visited[i] = false;
		}
}

int main(void)
{
	cin >> N >> M;

	func(0);
	return 0;
}
