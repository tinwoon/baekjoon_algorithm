# [백준 알고리즘](https://www.acmicpc.net/)


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



#### 24. bfs는 미리 점검하고 방문했다 함. => 점검하고 큐에 넣은 후 다음 while에 방문하는거 X



#### 25. 1234 -> 2341 -> 3412 처럼 한칸씩 이동하는 방법

 - `int alpha = (now % 1000)*10 + now / 1000;`
 - 반대로 1234 -> 4123 -> 3412 이렇게 한칸씩 이동하는 법은 `int alpha = (now % 10) * 1000 + now / 10;`
 - 

#### 26. BFS로 풀수 있나 없나는 정접의 개수로 알 수 있다.
  - 예를 들어 1525 퍼즐 문제의 경우 3X3의 퍼즐을 옮겨 답을 구하는 문제인데
  - | 8 | 2 |    |              | 1 | 2 | 3 | 
    | 7 | 1 | 3 |     =>     | 4 | 5 | 6 | 
    | 6 | 5 | 4 |              | 7 | 8 |   |
  - 이때 정점의 개수는 각각의 자리수에 수가 들어가는 모든 개수이므로 9!와 같다.
  - 물론 왼쪽 상단 순서대로 1 2 3 4 5 6 8 7 네모 순은 퍼즐 구조 특성상 나올 수 없으므로 실제론 9!보다 작다.
  - 

#### 27. map 자료구조 같은 경우 배열은 배열인데 A[]안에 문자열 또는 배열을 넣을 수 있는 구조
 - 이진트리로 구성되어 있다
 - pair 구조기 때문에 다음과 같이 사용할 수 있다
 ```c++
m1.insert(pair<int,int>(10,20));
m2.insert(pair<string,int>("BLOCKDMASK",27));
 ```

- 기본선언 `map<int, int> m;`

- pred를 통해 정렬기준 (오름, 내림)을 세운다. `map<int> m(pred);`

- 연산자 `m[key] = value`를 통해 원소 (key,value)를 추가 수정 가능



#### 28. `string m = "alph"`하면 `m.find('a')`를 실행하면 0이 나온다



#### 29. map 자료구조 count 

- map.count(key)하면 key에 해당하는 원소들의 개수를 반환



#### 30. 릴리즈와 디버깅 모드의 경우 굉장한 시간 차이가 날 수 있다

- release는 여러가지 최적화를 수행
- 디버깅은 작성한 코드 외에도 여러 작업을 수행하는 단점이 있음(STL에 디버그만 추가되는 코드, 특정 값 메모리 참조 등)



#### 31. 상하좌우 이동 알고리즘

```c++
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

for(int i=0; i<4; i++){
    int x = x + dx[i];
    int y = y + dy[i];
}
```



#### 32. 인접행렬 => `A[i][j]`가 있을 때 i 에서 j 로 가는 간선이 있으면 `A[i][j]=1`이다. 없으면 0

- 인접리스트 `A[1] = 2,5` 이렇게 있으면 1번 정점에 2,5가 연결되어 있다는 의미 (동적인 배열로 linked list지만 실제 구현할 때는 벡터를 주로 사용)

- 만약 가중치가 있다면 `A[1] = (2,2), (5,7) 이런식으로 가중치를 표현

- 인접행렬 : O(V^2) => V 는 정점의 개수

- 인접리스트: O(E) => E는 간선의 개수

-  대부분은 인접 리스트가 효율이 좋다

  > 인접행렬이 리스트보다 좋을 때는
  >
  > 1. 특정 정점에 해당하는 도착 정점을 찾을 때와
  > 2. u, v로 갈 때 v에서 u로 가는 정점이 있는지 알아야 할 때
  >
  > 하지만 인접 행렬은 정점이 100만개만 되도 100X100개가 필요
  >
  > 인접리스트는 한 정점과 연결된 나머지를 모두 찾아야 할 때 씀



#### 33. 그래프 탐색의 목적은 임의의 시작점 x에서 모든 정점을 1번씩 방문하는 것

- 그래프의 dfs

  ```c++
  void dfs(int x){
      check[x]=true;
      printf("%d", x);
      for(int i=1; i<=n; i++){
          if(a[x][i]==1 && check[i]==false){
              dfs(i);
          }
      }
  }
  ```

   => 방문한 순서대로 출력됨(시간 복잡도 for문 V x dfs V번 호출 = O(V^2) )

  

  > 이때 dfs는 정점의 개수만큼만 호출된다. 하지만 이 경우는 a가 인접행렬일때 이므로 인접리스트로 구현하면 

  ```c++
  void dfs(int x){
      check[x]=true;
      printf("%d", x);
      for(int i=0; i< a[x].size(); i++){
          int y = a[x][i];
          if(check[y]==false){
              dfs(y);
          }
      }
  }
  ```

 =>  시간 복잡도는 O(V + E) 



#### 34. 그래프 탐색인 bfs는 무조건 방문하기 전에 true해야 함

- 그래야 q에 중복된 정점이 안들어간다 (복잡도는 dfs랑 같음)

- 아래 코드는 인접리스트

  ```c++
  void bfs(int x){
      queue<int> q;
      check[1] = true;
      q.push(1);
      while(!q.empty()){
          int x = q.front();
          q.pop();
          printf("%d", x);
          for(int i=0; i<a[x].size(); i++){
              int  y = a[x][i];
              if(check[y]==false){
                  check[y]=true;
                  q.push(y);
              }
          }
      }
  }
  ```



