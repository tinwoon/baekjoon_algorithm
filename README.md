# [baekjoon_algorithm][https://www.acmicpc.net/]
 

![백준 랭크](https://user-images.githubusercontent.com/18729679/103272373-063c4280-4a00-11eb-9290-a6f271f53766.png)




###  1. 순열 알고리즘

``` c++
#include <stdio.h>

void swqp(int *a, int *b){
    int tmp;
    tmp = *a;
    *a= *b;
    *b = tmp;
}

void permutaion(int n,int r){
    if(r==0){
        ~~;
        return;
    }
    
    for(int i= n-1; i>=0; i--){
        swap (&arr[i], &arr[n-1]);
        permutation(n-1,r-1);
        swap(&arr[i], &arr[n-1]);
    }
}
```



### 2. 중복제거 알고리즘

- unique는 중복된 값을 맨 뒤로 보내고 그 값의 첫번째 iterator를 반환한다.

```c++
sort(letters.begin(), letters.end());
letters.erase(unique(letters.begin(), letters.end()), letters.end());
```

 

### 3. 공백포함 문자열 받기



```c++
scanf("%[^\n]s", s);
```



### 4. String 붙이기

```c++
string str3 = str1 + " " + str2;
```

```c++
str3.append(str4,0,4); //str의 0칸부터 4칸 붙이기
```

```c++
str3.append(5, '.'); // str3에 '.' 5개 붙이기
```



### 5. iterator

~~~c++
vector<int> v;
v.push_back(10);
v.push_back(20);
v.push_back(30);
v.push_back(40);
v.push_back(50);

vector<int>::iterator itr = v.begin();

cout<<iter[3]<<endl; //40
itr +=2;
cout<<*ier<<endl; //30
cout<<endl;

for(itr = v.begin(); itr !=v.end(); itr++){
    cout<< *iter<< endl;
}

return 0;

~~~



### 6. 순열

- 대신 v가 1,2,3,4 순일때 가능하다.
- 만약 v가 9,8,7,등 내림차순이라면 prev_permutation을 사용하면 된다.

~~~c++
do{
    
}while(next_permutation(v.begin(), v.end()));
~~~



### 7. 최대공배수



- 유클리드 호제법(두개의 자연수를 받아 최대 공약수를 받기 위해 2부터 두 자연수 중 작은 자연수까지 모두 나누어 보면서 가장 큰 공약수를 구할 수 있다.)
- 최소공배수는 a,b를 곱한거에 최대공약수를 곱하면 된다. (단 a>b)



~~~c++
int gcd(int a, int b){
    while(b!=0){
        int r = a%b;
        a=b;
        b=r;
    }
    return a;
}

int lcm(int a, int b){
    return a*b/gcd(a,b);
}
~~~



#### 8. 알고리즘 팁: 알고리즘 풀 때 sum값 등의 반환값이 int 값을 넘어가는지 확인할 것



#### 9. std::accumulate(v.begin(), v.end(),0)하면 배열의 합을 구할 수 있다 (#include <numeric>은 해야함)



#### 10. 단순히 두개를 고르는 거라면 조합보단 for문이 좋음

~~~c++
for(int i=0; i<num; i++){
    for(int j=i+1; j<num; j++){
        ~;
    }
}
~~~



#### 11. 형식지정자 %d, %ld, %lld



#### 12. 백트래킹은 브루트포스지만 정답이 아닐 때 바로 종료하는 것(부등호 문제에서 8<9<3이 들어가면 3이 성립하지 않자마자 바로 종료하는 것)



#### 13. int 범위 40억(-20억 ~ +20억 정도로)



#### 14. 이중벡터 초기화

~~~C++
arr[6][5];

vector< vector<int> > arr(6,vector<int>(5,0));

arr.assign(6,std::Vector<int>(5,0));
~~~



#### 15. 재귀는 void로 할 것, 예를 들어서 아래와 같이 하면 vector의 생성이 반복되어 메모리초과 발생.

~~~c++
vector<int> ~(i){
    vector<int> (i+1);
}
~~~

 

#### 16. 범위기반 for문

```c++
for(int i=0; i<10; i++){
    cout<<arr[i]<<endl;
}
//이거를 아래와 같이 변경 가능

for(int elem:arr){
    cout<<elem<<endl;
}
```



#### 17. 백트래킹 주요 양식

~~~C++
void ~(index){
    if(k==~){
        //기저사례
    }
    
    void ~(index+1)
    
}
~~~

#### 18. 비트연산

- `i&(1<<j)` 의 값은 비트의 값이다.
- 예를 들어 i==2, j==2이면, `i&(1<<j)` 는 2이다.



#### 19. `for(int i=0; i<(1<<5); i++)` 하면 00000 ~ 11111 까지의 모든 비트 수를 확인할 수 있다 (종이조각 문제)



#### 20. `equal_range( ~.begin(), ~end(), -num);` 에서 

- 1 1 2 4 4 4 4 4 4 5 5 7 8이 있을 때 
- lower bound는 크거나 같으면서 가장 작은 수
- upper bound는 크거나 같으면서 가장 작은 수이다.
- 4의 lower bound는 4,  4의 upper bound는 5이다.



- 이때 upper bound와 lower bound의 수를 위치를 빼면 같은 수의 개수를 찾을 수 있다.

-  만약 없는 수인 6을 생각해보아도 

    6의 lower bound는 7

    6의 upper boundsms 7, 즉 같은 인덱스이므로 빼면 0이 나온다



```C++
auto range = equal_range(second.begin(), second.end(), -num);
ans += range.second - range.first;
```



- 위와 같이 하면 ans에 -num의 개수가 ++된다.

  ##### 단 second는 정렬되어 있어야 한다!



#### 21. 이중벡터 초기화 => `vector< vector<int> > arr (6, vector<int>(5,0));`



 #### 22. pair

```C++
std::vector< std::pair<int, int> > connect;
connect.push_back(std::make_pair(a,b));

//정렬같은 경우 cmp함수 없이 sort(connect. begin(), connect.end()) 하면 first기준 정렬임(default)

//first 기준 정렬
bool cmp(connect pair<int,int> &a, const pair<int,int> &b){
    return a.first< b.first;
}

//second 기준 정렬
bool cmp(const pair<int,int> &a, const pair<int,int> &b){
    return a.second < b.second;
}
```

#### 23. dfs, bfs 양식

```c++
void dfs(int visit){
    visited[visit]=true;
    printf("%d", visit);
    
    for(int i=1; i< N+1; i++){
        if(!visited[i]&&connect[visit][i]==true){
            dfs(i);
        }
    }
    return;
}

void bfs(int visit){
    bfs_queue.push(visit);
    visited[visit]=true;
    while(!bfs_queue.empty()){
        int tmp = bfs_queue.front();
        bfs_queue.pop();
        printf("%d ",tmp);
    
    
        for(int i=1; i<N+1; i++){
    	    if(!visited[i]&&connect[tmp][i]==true){
    	        bfs_queue.push(i);
    	        visited[i]=true;
   	     }
  	  }
    }
    
    return;
}
```



#### 25. bfs는 미리 점검하고 방문했다 함. => 점검하고 큐에 넣은 후 다음 while에 방문하는거 X

