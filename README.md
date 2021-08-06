# [백준 알고리즘](https://www.acmicpc.net/)





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

#### 26. BFS로 풀수 있나 없나는 정점의 개수로 알 수 있다.
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



#### 35. (A+B)%C는 ((A%C)+(B%C))%C와 같다.

- 마찬가지로 `(A*B)%C`는 `((A%C)*(B%C))%C`와 같다.

- 하지만 (6-5)%3을 하면 1이 나와야 정상이지만 `((6%3)-(5%3))%3`하면 `-2%3`이 된다.
- 이때 C++, JAVA의 경우 -2, python은 1이 나온다.
- 따라서 -가 나오지 않게 하려면 `(a%c - b %c)`의 결과는 `-c < (a%c) - (b%c) < 2c`이므로  `0 < (a%c) - (b%c) + c < 3c` 이다.
- 따라서 음수면 c를 한번 더 더해주면 된다.
- `애초에 %연산은 항상 c를 다시 더해주면 된다.`



#### 36. (a/b) %c가 구하고 싶으면 b가 0일때 문제가 생긴다. 이때 페르마의 공식을 사용하면 된다.

- (a/b)%c = (a*b^(c-2) )%c 와 같다. (단 c는 소수, a,b는 서로수)
- 사실 쓸 일 거의 없음

#### 37. 소수인지 알려주는 알고리즘 (복잡도 O(N))

```c++
bool prime(int n){
    if(n>2){
        return false;
    }
    for(int i=2; i<=n-1;i++){
        if(n%i==0){
            return false;
        }
    }
    return true;
}
```

- 하지만 N이 소수가 되려면 2보다 크거나 같고, N/2보다 작거나 같은 자연수로 나누어 떨어지면 안된다는 점을 이용하지 않은 식이다.

  > N = a * b일 때 a의 최소값은 적어도 2이상이고 b는 a가 2일 때 N/2이다. 즉 소수는 a와 b의 곱셈이기 때문에 어떻게 해서든 2보다 클거고 N/2보다 작을 것이다.
  >
  >  즉, `i < =n-1`을 `i <=n/2`로 변경하면 된다. 

- 여기서 더 줄일 수 있다.

  N이 소수가 아니면 N = a*b에서 (a<=b), a > b라면 두 수를 바꿔서 항상 a<=b로 만들 수 있고 두수 a와 b의 가장 차이가 작은 경우는 sqrt(n)이다.

  따라서 sqrt(n)까지만 검사해보면 된다.

  예를 들어 24의 약수 1,2,3,4,6,8,12,24에서 sqrt(24) = 4.xx전까지인 1,2,3,4까지만 검색해도 충분하다.

  즉, `i <= n-1`을 `i*i<=n `으로 변경하면 된다.

#### 38. 소수를 구하는 알고리즘(에라토스테네스의 체)

```c++
int prime[100];
int pn = 0;
bool check[101];
int n = 100;
for(int i=2; i<=n; i++){
    if(check[i]==false){
        prime[pn++] = i;
        for(int j=i*i; j<=n; j += i){
            check[j]=true;
        }
    }
}
```

#### 39. 외판원 문제(TSP)

> 1번부터 N번까지 번호가 매겨져 있는 도시가 있다.
>
>  한 도시에서 시작해 N개의 모든 도시를 거쳐 다시 원래 도시로 돌아오려고 한다.(한번 갔던 도시로는 다시 갈 수 없다.)
>
> 이때, 가장 적은 비용을 구하는 문제이다.
>
> 순열을 사용하기 위해서는 N값을 알아야 하는데 N! * N이 수열의 복잡도이다.  
>
> N이 10이면 10! * 10 = 36288000이다. 즉 1억번이하기 때문에 시간초과가 발생하지 않는다.

#### 40. 11222를 next_permutation해도 중복을 해결하여 알아서 처리해준다. 이때 복잡도는 5!/2!*3!이다.



#### 41. XOR연산은 같으면 0, 다르면 1이다.

| A    | B    | A^B  |
| ---- | ---- | ---- |
| 0    | 0    | 0    |
| 0    | 1    | 1    |
| 1    | 0    | 1    |
| 1    | 1    | 0    |



#### 42. not연산은 자료형에 따라 결과가 달라진다.

A = 83 = 1010011

~A = 10101100(8비트 자료형일 경우)

~A = 11111111 11111111 11111111 10101100(32비트 자료형일 경우)

또, unsigned, signed에 따라서 보여지는 값이 다르다.



#### 43. A<<B는 A*2^B와 같다.

- 마찬가지로 A>>B는 A/2^B와 같다.
- (A+B)/2 는 (A+B)>>1로 쓸 수 있다.



#### 44. {1,3,4,5,9} = 570 (1000111010)

- 0이 포함되어 있는지 검사

  `570 & 2 = 570 & (1<<0) =0`이다.

- 1이 포함되어 있는지 검사 

  ` 570&2=570&(1<<1)=2`이다.



#### 45. {1,3,4,5,9} = 570 (1000111010)에서 

- 1추가하기

  > 570 | 2 = 570 | (1<<1) = 570 (1000111010)

#### 46. {1,3,4,5,9} = 570 (1000111010)에서 

- 1제거하기

  >  570 & ~2 = 570 & ~(1<<1) = 568



#### 47. {1,3,4,5,9} = 570 (1000111010)에서 

- 1토글하기

  > 570^2 = 570^(1<<1) = 560



 #### 48.비트연산자는 - 가 먼저임

- 근데 그냥 ()치는게 좋습니다(굳이 외우지 마세요)



#### 49. C++에는 bitset이 있음. long long 64비트 이상 비트를 만들고 싶을 때 사용 => 딱히 쓸 일 없음



 #### 50. `<string>`헤더에 std::to_string(i)



#### 51. 그림과 같이 A와B로 나눌 수 있으면 이분 그래프이다. 

- A에 포함되어 있는 정점끼리 연결된 간선이 없음.
- B에 포함되어 있는 정점끼리 연결된 간선이 없음
- 모든 간선의 한 끝점은 A에, 다른 끝점은 B에 
- 색을 기준으로 한 노드의 겹치는 다른 색에 같은 색깔의 노드가 연결되어 있으면 안됨.



![img](https://t1.daumcdn.net/cfile/tistory/99BA79335A14305512)

#### 52. q.push(std::pair<int,int>(x,y))하면 넣을 수 있음.



#### 53. 2차원 벡터에서 가장 큰 값의 인덱스를 알고싶으면 `max_element(V.begin(), V.end())`하면 됨

- `max_element(V.begin(), V.end())` 하면 됨
- `min_element`도 있음. (반환값은 iterator임)



#### 54. if문은 0만 아니면 true => if(-1) == true임



#### 55. tuple 사용법

```c++
std::tuple<int, int, int> t;
printf("%d", std::get<0>(t));

int v4 =4;
double v5 = 5;
int v6 = 6;
double v7 =7;

std::tuple<int, double, int, double> c(0,1,2,3);
std::tie(v4, v5, v6, v7) = c;
printf("%d %d %d %d", v4,v5,v6,v7);
```

> 0 1 2 3



#### 56. bfs는 가중치가 없어야 한다. 만약 있다면 큐 두개로 해야한다. (또는 deque가 있는데 deque가 더 쉬움)

> 숨바꼭질 3에서 (13459)



#### 57. 다이나믹 프로그래밍(동적계획법)

- Dynamic의 의미가 있는게 아니라 멋져보여서 씀...
- 큰 문제를 작은 문제로 나눠서 품(분할 정복과 비슷하지만 차이는 다이나믹은 작은 문제가 중복되지만 분할은 x)

>- DP의 특징
>
>  1. Overlapping Subproblem => 부분 문제가 겹친다.
>  2. Optimal Substructure => 최적 부분 구조
>
>- Overlapping problem
>
>  - 피보나치 수열
>
>    `F(n) = F(n-1) + F(n-2)` (작은 문제로 나누어서 푼다) 
>
>    이때 N - 1번째 피보나치를 보면 `F(n-1) = F(n-2) + F(n-3)`으로 중복되서 발생한다.(overlapping)
>
>- Optimal Substructure
>
>  - 문제의 정답을 작은 문제의 정답에서 구할 수 있다.
>  - 서울에서 부산을 가는 답이 `서울 -> 대전 -> 대구 -> 부산`이라면 대전에서 부산을 가는 법은 `대전 -> 대구 -> 부산`이다.
>  - 즉, 큰 답에서 작은 답을 볼 수 있다.
>
>- Optimal Substructure를 만족한다면, 문제의 크기에 상관없이 어떤 한 문제의 정답은 일정하다.
>
>  > 1. 피보나치에서 10번째 피보나치 수를 구하면서 구한 4번째 피보나치 
>  > 2. 피보나치에서 9번째 피보나치 수를 구하면서 구한 4번째 피보나치 수 
>  > 3. 항상 1,2에서 구한 4번쨰 피보나치 수는 같다.
>
>- 즉, 정답을 구했으면, 정답을 어딘가에 메모해 둔다.(Memoization)
>
>  ```c++
>  int Fibonacci(int n){
>      if(n<=1){
>          return n;
>      }else{
>          return fibonacci(n-1) + fibonacci(n-2);
>      }
>  }
>  ```
>
>  시간 복잡도 : `O(2^N)`=> 또한 이미 구한 값을, 굳이 또 구하게 됨.
>
>   ```c++
>  int memo[100];
>  int Fibonacci(int n){
>      if(n<=1){
>          return n;
>      } else {
>          if(memo[n]>0){
>              return memo[n];
>          }
>      }
>      memo[n] = fibonacci(n-1) + fibonacci(n-2);
>      return memo[n];
>  }
>   ```
>
>  시간 복잡도 : `O(N)`

- 다이나믹을 푸는 방법은 두가지이다.

  > 1. Top-down(큰 문제를 작게) => 재귀로
  > 2. Bottom_up(작은 문제를 크게) => 함수로
  >
  > ```c++
  > //피보나치 bottom up
  > int Fibonacci(int n){
  >     d[0]=0;
  >     d[1]=1;
  >     for(int i=2; i<=n; i++){
  >         d[i]=d[i-1]+d[i-2];
  >     }
  >     return d[n];
  > }
  > ```
  >
  > - Top down 과 Bottom up 중 어떤 방식으로 풀면 되나? => 자기가 자신 있는 방식으로
  > - Top down으로만 풀 수 있고, Bottom up만으로 풀 수 있는 문제는 있다. 하지만 이런 문제는 굉장히 어렵기에 이걸 풀 정도면 이미 DP는 다 풀 수 있다.
  > - 시간복잡고는 Top down과 Bottom up 중 누가 빠른지 알 수 없다. => 거의 비슷
  > - 물론 Top down은 필요한 것만 풀고 bottom up은 전체를 풀기 때문에 Top down이 빠를 수도 있지만 재귀라 느릴 수도 있음
  > - 백준 조차도 Top down을 bottom up배우고 7년 뒤에 배웠다.

- Bottom up
  1. 문제의 크기가 작은 문제부터 차례대로 둔다. `for(int i=2; i<=n; i++)`
  2. 문제의 크기를 조금씩 크게 만들면서 문제를 점점 푼다.
  3. 작은 문제를 풀면서 왔기 때문에, 큰 문제는 항상 풀 수 있다. `d[i]=d[i-1]+d[i-2];`
  4. 그러다보면 언젠가 풀어야하는 문제를 풀 수 있다. `d[n]`을 구하게 된다.

- DP의 시간 복잡도 = 전체 문제의 개수(배열의 크기) * 1문제 푸는 시간(`O(N)`)



#### 58. `std::max`는 인자를 두개만 가능하게 함. `ex) std::max(i,j);`

- 하지만 세개 이상을 하고 싶으면 {}를 넣으면 된다. `ex) std::max({i,j,k});`

- 비슷한 걸로 `std::max_element(*itr, *itr)`도 있음

  > 대신 반환 값이 itr이므로 `*std::max_element(v.begin(), v.end())해야 값이 나옴`



#### 59. 가중치 bfs => Deque (탈옥문제)

```c++
void bfs(int i, int j, std::vector< std::vector<int> > &value) {
	std::deque< std::pair<int, int> >q;
	q.push_front(std::make_pair(i, j));
	value[i][j] = 0;

	while(!q.empty()){
		auto front = q.front();
		q.pop_front();

		for (int k = 0; k < 4; k++) {
			int nx = front.second + dx[k];
			int ny = front.first + dy[k];
			if (nx >= 0 && nx < M + 2 && ny >= 0 && ny < N + 2) {
				if ( map[ny][nx] != '*') {
					if (value[ny][nx] != -1) continue;
					if (map[ny][nx] == '#') {
						value[ny][nx] = value[front.first][front.second] + 1;
						q.push_back(std::make_pair(ny, nx));
					}
					else {
						value[ny][nx] = value[front.first][front.second];
						q.push_front(std::make_pair(ny, nx));
					}
				}
			}
		}
	}
	
	
}
```



#### 60. 대소문자 구별 

- 소문자 `if(islower(a[0]))`
- 대문자  `if(isupper(a[0]))`

- 소문자로 변환 `a[0]=tolower(a[0])`

- 대문자로 변환 `a[0]=toupper(a[0])`



 #### 61. bfs 문제 푸는방법 팁

- 보통 이제까지는 q를 담은 값을 확인하면서 답을 찾으면 중지시킴
- 하지만 담은 값들을 먼저 구해놓고 하는게 좋을 때가 있음 `ex) 탈옥, 4991 로봇청소기`
- 로봇청소기 같은 경우 로봇거리별 청소 순서를 수열로 정해서 bfs한 값들을 대소비교함.
- bfs를 하면서 구하지 X => bfs를 다하고 구함.

> 이런 알고리즘을 flood fill이라 함.



#### 62. 8111 0 과 1

- 이 문제의 핵심은 int형 범위를 한참 초과하는 문제를 dp로 풀어가는 과정의 예시

- 해당 알고리즘은 유용하게 쓰일 여지가 많으니 외워두기

  ```c++
  std::string bfs(int n) {
  	std::queue<int> q;
  	q.push(1%n);
  	how_digit[1 % n] = 1;
  	from[1 % n] = 1;
  	div_value[1 % n] = 1%n;
  	std::string ans = "";
  
  	while (!q.empty()) {
  		auto front = q.front();
  		q.pop();
  		for (int i = 0; i <= 1; i++) {
              //여기 핵심
  			int next = ((front * 10) % n + i) % n;
  			if (div_value[next] == -1) {
  				div_value[next] = front;
  				from[next] = i;
  				how_digit[next] = how_digit[front] + 1;
  				q.push(next);
  			}
              //여기까지
  		}
  	}
  	if (div_value[0] == -1) {
  		ans = "BRAK";
  	}
  	else {
  		int previous = 0;
          //여기부터
  		for (int i = 0; i < how_digit[0]; i++) {
  			ans.append(std::to_string(from[previous]));
  			previous = div_value[previous];
  		}
  		std::reverse(ans.begin(),ans.end());
          //여기까지
  	}
  
  	return ans;
  }
  ```

#### 62. DP에서는 0으로 초기화하는 것 보다 -1로 초기화하는 것이 좋다(0자체가 답일수도, 의미를 가질 수도 있음)



#### 63. 팰린드롭 => 거꾸로 읽어도 똑같은 단어. `ex)토마토`



#### 64. 1,2,3 더하기 4(중복제거 문제) => 자주 사용되는 로직

- 구하고자하는 값을 n이라고 할 때

```c++
int calculate() {
	dp[0] = 1;
	for (int i = 0; i < 3; i++) {
		for (int j = 1; j <= n; j++) {
			if (j-number[i]>=0) {
				dp[j] += dp[j - number[i]];
			}
		}
	}
	return dp[n];
}

```

- 끝의 수가 1,2,3이므로 오름차순으로 들어가 있음. 즉, 2+1+3이 나올 일이 없음(1+2+3은 나와도)



#### 65. 평범한 배낭 알고리즘 (knapsack problem)

```c++
// j를 K부터 시작하면 이미 들어갔던 물품이 다시 들어가는 것을 방지할 수 있음.

int calculate() {
	
	for (int i = 0; i < N; i++) {
		for (int j = K; j >= 1; j--) {
			if (j - weight[i] >= 0) {
				dp[j] = std::max(dp[j], dp[j - weight[i]] + cost[i]);
			}
		}
	}

	return dp[K];
}


```

#### 66. 괄호문제 (10422)

- `dp[i][j]`를 길이가 i인데 닫히지 않은 개수가 j인 값이라 정의한다면

  > `D[i-1][j+1]` 은 `D[i][j]`에서 ')'를 뺀 값이고
  >
  > `D[i-1][j-1]` 은 `D[i][j]`에서 '('를 뺀 값이고



#### 67. queue는 iterator기반 탐색을 제공하지 않는다.

- begin(), end() 등을 사용하려면 deque를 써야함.

#### 68. emplace_back은 push_back과 완전히 비슷하지만 성능면에서 우수하다.
 - 이제까지의 push_back을 emplace_back으로 대체해도 상관 없다.

#### 69. 재귀로 모든 n가지의 경우의 수를 찾는 방법
 - 예를 들어 주사위 n번이 각각 나오는 수는 6을 n번 곱한 값이다.
 ```c++
 void calculate(int num_dice){
     if(){
         //기저사례
     }

     for(int k=0; k<6; k++){
         value[num_dice]=k;
         calculate(num_dice+1);
     }
 }
 ```

#### 70. inline 함수는 다음과 같이 함수코드 자체를 변경해준다.
 ```c++
 inline int min(int x, int y){
     return x>y ? y:x;
 }

 int main(){
     std::cout<<min(5,6)<<endl;
 }

 //다음과 같이 변경되게 된다.
 int main(){
     std::ctour<<(5>6?6:5)<<endl;
 }

 ```

#### 71. set자료구조 => key값은 중복이 허용되지 않는다.

 - 원소가 insert 멤버함수에 의해 삽입되면 원소는 오름차순으로 자동 정렬된다.
 ```c++
 std::set<int> ans;
 t=10
 while(t){
     ans.insert(t);
     t--;
 }
 ```

 - => ans에 {1,2,3,4,5,6,7,8,9,10}

 - 여기에 `ans.insert(4)`해도 ans는 `{1,2,3,4,5,6,7,8,9,10}`임

#### 72. itr은 ++를 한다해서 크기라 생각하면 안된다.



#### 73. for문에서 `for(auto itr = v.begin(); i!= v.end(); i++)`을 해야지 `i < v.end()`하면 안됨



#### 74. itr을 뒤부터 참조하고 싶으면 `for(auto itr = v.rbegin(); itr != vr.end(); itr++)`하면 됩니다!



#### 75. 물통 문제처럼 돌그룹(12886)문제는

- A,B,C 3개의 돌의 visited를 하기 위해 `visited[A][B][C]`를 해야하지만 마찬가지로 C는 전체 돌의 개수에서 A와B의 개수를 빼면 나오므로 `visited[A][B]`로 setting해도 풀 수 있다.

#### 76. 벽부수기나, 말이 되고 싶은 원숭이 문제처럼 두 개의 조건을 가지는 문제가 있을 때는 `visited[nx][ny]`만 하는게 아닌 `visited[nx][ny][num]`처럼 벽을 몇 개 뿌신 상태로 벽을 넘어갔는지를 저장하는 visited로 실행해야 함



#### 77. ==BFS 단축 알고리즘!! floodfill과 비슷한 느낌임(백준 3197번 백조의 호수)==

```c
bool water_check[1500][1500]
char a[1500][1500]    
    
    
int main(){
    queue< pair<int,int> > water, next_water;
    int n,m;
    scanf("%d %d", &n, &m);
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j+=){
            scanf(" %1c", &a[i][j]);
            if(a[i][j] == '.'){
                water.emplace(make_pair(i,j));
                water_check[i][j] = true;
            }
        }
    }
    
    //map에서 .은 물을 의미함
    //water에는 물의 좌표를 모두 넣어둠.
    while(!water.empty()){
        int x = water.front().first;
        int y = water.front().second;
        water.pop();
        //이걸 해주는 이유는 기존의 .이 아닌 X로 된 얼음의 값을 녹였음을 표현하기 위해 X를 .으로 변경하는 것
        a[i][j] = '.';
        
        for(int k=0; k<4; k++){
            int nx = x + dx[k];
            int ny = y + dy[k];
            if(nx < 0 || nx >= n || ny < 0 || ny >=m) continue;
            //이미 방문했던 water는 방문하지 않고
            if(water_check[nx][ny]) continue;
            //만약 water에 들어가 있지 않다면(즉, X였다가 위의 a[i][j] = '.'에 의해 방금 .으로 바뀌었다면)
            if(a[nx][ny] == '.'){
                water.push(make_pair(nx,ny));
                water_check[nx][ny] = true;
            //반대로 아직 X인 상태라면 다음번 부터는 .으로 바뀔 얼음이므로 next_water에 넣어준다.
            //그 다음 water_check에 넣어주면 기존의 bfs의 단점인 처음부터 다시 탐색하는 과정을 단축시켜 시간을 절약할 수 				있다.
            }else{
                next_water.push(make_pair(nx,ny));
                water_check[nx][ny] = true;
            }
        }
    }
    //next_water에는 다음부터 녹을 얼음의 좌표를 저장해 놓았기 때문에 다음부터 물이 될 자표임으로 water에 넣어주고 초기화
    water = next_water;
    next_water = queue< pair<int,int> >();
    
}    
    
	
```

#### 78. `#include <numeric> 하고 iota(v.begin(), v.end(),0);`하면 벡터 v에 0부터 한칸씩 들어간 값이 들어있음.



#### 79. DP 문제는

> 1. 문제에 보면 변수가 항상 존재하는데 이 변수를 모두 찾아서 점화식의 형태로 넣고
> 2. 반례가 없다는 확신은 어떤 상황 => 다른 상황에서 나오는 모든 경우를 다 찾았으면 반례가 없다고 확신하기 
>    - AB문제는 A사용, B사용을 제외하면 문제가 나올 수 있는 방법이 없으니 반례가 없다.
> 3.  DP로 문제를 푸려면 가장 작은 단위를 찾아서 누적해 찾아가기.



#### 80. AB 문제 점화식

```c++
#include <iostream>
#include <vector>
#include <string.h>

int N, K;
bool dp[51][51][1226];
char rst[51];

//문자열의 길이가 n이고, a의 개수는 a_num인 문자열 중 조건을 만족하는 쌍의 개수가 k개가 일 때
bool calculate(int n, int a_num, int k) {
	
	
	if (n == N) {
		if (k == K)	return true;
		else return false;
	}
	if (dp[n][a_num][k]) return false;
	dp[n][a_num][k] = true;

	//A를 넣을 때
	rst[n] = 'A';
	if (calculate(n + 1, a_num + 1, k)) return true;

	//B를 넣을 때
	rst[n] = 'B';
	if (calculate(n + 1, a_num, k + a_num)) return true;
	
	return false;

}

int main() {
	scanf("%d %d", &N, &K);
	if (calculate(0, 0, 0)) std::cout << rst;
	else printf("-1");
}
```

#### 81. a^b를 빠르게 구할 수 있다.(분할 정복으로)

```c++
int calc(int a, int b){
    int ans = 1;
    while(b>0){
        if(b%2==1){
            ans *= a;
        }
        a = a*a;
        b/=2;
    }
    return ans;
}
```

#### 82. nCk = n!/k!*(n-k)! 에서 20C3은 20!/3!*17! 이지만 20!은 2의 31승보다 크기 때문에 int의 값을 넘어간다.

#### 따라서, 파스칼의 삼각형을 통해 n번째 줄에서 k번째 오는 수를 계산하면 된다. 



#### 83. memset은 byte 단위로 초기화하는데 두번째 인자는 0, -1만 빼고 이상하게 초기화 된다.

> 0, -1은 비트로 하면 00000000... , 11111111... 이기 때문
>
> 따라서 `std::fill(&dp[0][0][0], &dp[1001][1001][2] + 1, -1000000);`을 쓰는 것이 좋다.



#### 84. sort의 compare 함수는 true가 나오면 유지 false가 나오면 변경이다.

```c++
bool compare(int a, int b){
    if(a<b) return false;
    else return true;
}
//a<b 이면 안되도록하여 a>=b순으로 정렬되도록 sorting 해준다.
```



#### 85. dfs, bfs 형식 지킬 것! 

- 괜히 while문을 통해 둘의 비슷한 부분으로 엮어서 문제풀다 순서 섞여서 몇시간 동안 반례 찾지 않기(백준 미로찾기 17090번 문제처럼 틀리지 않기)

#### 86. int형 INF를 선언하기 위해서는 limits.h 헤더를 include하면 간단하게 사용할 수 있다.

- INT_MIN, INT_MAX 값이 최대 값이니 활용할 것



#### 87. 나머지 합 공식을 생각해보면 모듈러 연산의 중요성을 알 수 있다.

> dp[n]의 의미는 0부터 K까지 더한 값을 sum이라 했을 때, 나머지가 n인 값의 총 개수이다.
>
> 이 값을 알면 dp[i]*dp[i]-1/2를 하면 나머지가 i인 값들의 경우의 수를 구할 수 있다.
>
> 왜 둘의 나머지가 같은 값의 경우의 수를 구하냐면 [i,j]구간의 합은 sum[j] - sum[i]이고,
> 구간의 합이 M으로 떨어지는 (i,j)는 (sum[j]-sum[i])%M == 0이 되면 M으로 떨어지는 것이다.
>
> 이 식을 모듈러 연산으로 해보면 sum[j]%M == sum[i]%M이 되는 것으로 sum의 나머지가 같은 값 끼리 두개씩 고르는 경우의 수를 고르면 된다.
>
> 즉, dp[i]에는 나머지가 i인 sum의 개수가 들어 있으므로 그 개수에서 두개씩 고르는 조합의 공식은 dp[i] * (dp[i] - 1) / 2;이다.



#### 88. 팰린드롬 문제의 중요성은 dp의 방식이다.(쿠* 코딩테스트 문제)

- `dp[s][e]`로 선언하면 해당 문제를 쉽게 풀 수 있다.

  s부터 e까지의 문자열이 팰린드롭이면 1아니면 0을 추가한다.

#### 89. 배열 B의 값 문제는 floodfill과 비슷한 형태이다.

- 미리 B를 구하기 위한 A원소의 값을 몇번씩 더해주는지 규칙을 찾아 행렬로 만들어 곱하고 빼면 된다.

#### 90. 트리 순회(후위 전위 중위 순회)는 관련 공식처럼 알고리즘이 정해져 있다.

- `void calculate(int in_begin, int in_end, int post_begin, int post_end)`로 선언해 재귀적으로 구현한다.
- 이때 위처럼 inorder의 begin, inorder의 end, postorder의 begin, postorder의 end 처럼 구현하는 이유는 각각의 순회별로 왼쪽노드의 크기와 오른쪽 노드의 크기, 그리고 그 노드의 root값을 알기 위함이다.

```c
#pragma warning(disable: 4996)
#include <iostream>
#include <vector>
#include <algorithm>

int N;
std::vector<int> in_order;
std::vector<int> post_order;
//i번 node는 inorder의 i번째에 있다.
int find_index[100001];

//index는 n번 노드를 의미한다.
void calculate(int in_begin, int in_end, int post_begin, int post_end) {
	if (in_begin > in_end || post_begin > post_end) return;

	int root = post_order[post_end];
	printf("%d ", root);
	//왼쪽으로 이동
    //다음과 같이 매개변수를 놓는 이유는 begin과 end사이가 각각의 순위 별 사이즈가 되기 때문이다.
    //여기서는 inorder의 begin부터 end까지를 알면 왼쪽 노드의 inorder사이즈를 알 수 있고 postorder도 마찬가지이다.
	calculate(in_begin, find_index[root] - 1, post_begin, post_begin + (find_index[root] - in_begin) - 1);
	//오른쪽으로 이동
	calculate(find_index[root] + 1, in_end, post_begin + (find_index[root] - in_begin)  ,post_end - 1);
	return;
}


int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		int node_num;
		scanf("%d", &node_num);
		in_order.emplace_back(node_num);
		//node_num번 노드는 i번째에 있다.
		find_index[node_num] = i;
	}
	for (int i = 0; i < N; i++) {
		int node_num;
		scanf("%d", &node_num);
		post_order.emplace_back(node_num);
	}
	calculate(0, N-1, 0, N-1);
}
```

#### 91. itr 내부에 pair를 접근해야할 때가 있다.

- 예를 들면 `std::vector< std::pair<int, int> > vp`에서 pair구조를 접근하려면 다음과 같이 하면 된다.

  > for(auto itr = vp.begin(); itr!=vp.end(); itr++){
  >
  > ​	printf("%d\n", itr->first);
  >
  > ​	printf("%d\n", itr->second);
  >
  > }



#### 92. struct 구조체를 vector에 넣는 방법도 있다.(백준 17472 다리만들기2)

- `bridges.emplace_back(bridege{i,j,is_connected[i][j]});`가 중요하다.

 ```c++
 struct bridge {
     int from, to, cost;
 };
 std::vector< bridge > bridges;
 
 void input_bridge(){
     for(int i=1; i<sum_count; i++){
         for(int j=i+1; j<sum_count; j++){
             if(is_connected[i][j]){
                 bridges.emplace_back(bridege{i,j,is_connected[i][j]});
             }
         }
     }
 }
 ```



#### 93. DAG(Direct Acyclic Graph)란 사이클이 없는 방향 있는 그래프를 의미한다.

![image](https://user-images.githubusercontent.com/18729679/116411421-aa2fe080-a870-11eb-8bdc-003bfdab01fb.png)

> 보통 선행관계를 포함할 때 사용한다.
>
> 예를 들면 게임에서 1번 스킬을 찍어야 4번 스킬을 사용할 수 있고, 건물로 예를 들면 1,2번 건물을 지어야 4번 건물을 지을 수 있다는 의미를 말한다.



#### 94. DAG에서는 위상 정렬이라는 알고리즘을 사용해서 순서를 찾게 된다.(BFS, DFS 둘다 가능)

> 그래프의 간선  u -> v가 u가 v보다 먼저라는 의미일 때 정점의 순서를 찾는 알고리즘이다.
>
> 예를 들어보면 아래와 같다.
>
> ![image](https://user-images.githubusercontent.com/18729679/116412343-8e790a00-a871-11eb-979d-6edfa472b2ee.png)
>
> 다음과 같은 표에서 1,2,3,4,5,6,7,8,9 번 순으로 방문이 가능한지 확인해보자.
>
> 1. 1번, 2번, 3번 까지의 방문은 가능하다.
> 2. 4번의 경우 1,2번이 방문되었기 때문에 방문할 수 있다.
> 3. 5번의 경우 3번이 방문되었기 때문에 방문할 수 있다.
> 4. 6번의 경우 불가능하다. 6번을 방문하기 위해서는 5번과 7번을 방문해야하는데 7번을 방문하지 않았기 때문에 할 수 없다.
>
> 반면에 1,2,3,4,5,7,6,8,9 나 1,2,9,3,5,4,7,6,8은 방문이 가능하다.

- 방향 그래프에서는 차수라는 것이 존재하는데 차수는 in-degree, out-degree가 존재한다.

> 차수는 어떤 정점과 연결된 간선의 개수를 의미한다.
>
> 이 중에서 들어오는 간선의 개수를 in-degree, 나가는 간선의 개수를 out-degree라고 정의한다.

- 따라서 위상 정렬을 찾는 방법은 그래프에서 indegree의 값이 0이 되면 갈 수 있음을 의미하고 아니면 빼면 된다. (BFS를 이용한다.)

> 위상 정렬의 핵심은 indegree의 값을 계속해서 확인하면서 보면 된다.
>
> 예를 들어 위 그래프에서 1, 2, 3번 까지 방문했을 때 4번의 경우 원래 indegree는 2였으나 1번을 방문했기에 -1이 되고, 2번을 방문했기에 -1이 되어 0이 된다.
>
> 즉,  현재 노드에서 갈 수 있는 다음번 노드 중 indegree값이 0인 노드를 BFS의 큐에 저장하면 된다.

- 더 자세히 설명하면 다음과 같은 알고리즘으로 구현할 수 있다.

> 1. in-degree가 처음부터 0인 점을 초기 큐에 넣는다. (위의 그래프에서는 1,2,3이 indegree가 초기부터 0이다.)
> 2. 맨 처음 큐에서 값을 빼고 indegree값을 수정한다. (위의 그래프에서는 1이 나오면서 4의 indegree는 -1이 되고, 9의 indegree는 0이 되어 9를 큐에 저장한다.)
> 3. 이를 계속 반복하면 된다.



#### 95. 위상정렬 알고리즘은 DFS로도 풀 수 있다.



#### 96.  배열 초기화는 필수이다. => 컴파일러에 맡기지 않기



#### 97. `priority_queue<int> q;`의 정확한 자료형은 다음과 같다.

```c
priority_queue<int> q< int, vector<int>, less<int> > q;
```

- 본래는 다음과 같이 정의를 하게 되는데 less의 경우 내림차순으로 q를 뱉어내는 방식이다.
- 만약 오름차순으로 뱉어내고 싶다면 greater를 넣으면 된다.



#### 98. 범위 기반 for문 팁(백준 17071 숨바꼭질5번 문제)

```c++
for (int y : {x-1, x+1, 2*x}){
    //y에 x-1, x+1, 2*x를 순서대로 대입한다.
}
```



#### 99. map에 insert와 emplace의 차이점

- 다음과 같은 차이가 있다.

  > map::insert
  >
  > - insert를 사용하면 key와 value의 pair를 삽입할 수 있다.
  >
  > ```c++
  > std::map<int, int> dic;
  > dic.insert(std::make_pair(1,3));
  > ```
  >
  > map::emplace
  >
  > - insert와 비슷하지만 이쪽은 값을 key와 value의 생성자에 전송한 값을 구축한다.
  >
  > ```c++
  > std::map<int,int> dic;
  > dic.emplace(1,3); //dic.insert(std::make_pair(1,3))와 같다.
  > ```
  >
  > 

#### 100. 트리의 지름은 다음과 같은 성질을 가진다.

- 트리에서 어떤 두 노드를 선택해서 양쪽으로 쫙 당깅 때, 가장 길게 늘어나는 경우가 있을 것이다.
-  이럴 때 트릐의 모든 노드들은 이 두 노드를 지름의 끝 점으로 하는 원 안에 들어가게 된다.

![image](https://user-images.githubusercontent.com/18729679/119232351-eb5d9c80-bb5f-11eb-8a8c-9a7eb4e58170.png)

- 이런 두 노드 사이의 경로의 길이를 트리의 지름이라 한다.

- 즉, 트리의 지름을 찾기 위해서는 다음과 같은 방법으로 진행하면 된다.

  > 1. 랜덤의 한 노드로 부터 DFS로 가장 깊은 노드를 찾는다.(시작점)
  > 2. 그 시작점으로 부터 가장 큰 가중치를 찾아 가며 노드를 확인하면 된다. 즉, 두번의 DFS를 진행하면 된다.

#### 101. 체스판 문제 처럼 `dp[x][y]`가 아닌 `dp[x][y][num]` 로 visited를 만드는 것이 중요하다.



#### 102. 전역이 아닌 지역변수는 memset을 하지 않으면 선언 당시 배열이 0으로 초기화되어있지 않다.

- `int value[20]`을 지역변수로 선언하면 0으로 초기화되어있지 않다.



#### 103. 문제에 나와 있지 않는 내용이 반례가 될 수 있다.

- 최소비용 구하기2(다익스트라) 문제의 경우 A 도시에서 B 도시로 가는 경로가 여러개가 있을 수 있어서 생기는 문제이다. (1번 도시에서 2번 도시로 가는 경우가 가중치가 3인거 하나랑, 1번에서 2번 도시 가중치 5인개 나올 수 있다) => 좀 문제가 억지스러운 면도 있다.



#### 104. pair 자료구조의 경우 등호 연산자로 비교가 가능하다.

- 예를 들어 `pair<int,int> a(10,2)`와 `pair<int, int> b(10,3)`의 경우 `a>b`가 성립한다.



#### 105. 벌집(1385)문제의 경우 2차원 배열에 벌집 모양을 구현하면 되는 문제이다.

![image](https://user-images.githubusercontent.com/18729679/121537811-396b0f00-ca3f-11eb-96b4-1591d6aade86.png)

- 다음 이미지처럼 구현이 가능하다.



 #### 106. 제 1의 스털링 수란 다음과 같다. (박스안의 열쇠 문제)

> n개의 데이터를 k 개로 나눈 값을 S(n,k)라 정의할 때
>
> `S(n,k) = S(n-1, k-1) + k*S(n-1, k)` 가 성립한다.
>
> 위 점화식의 원리는 간단하다.
>
> - n-1 명의 학생이 있는 학급에 전학생이 한명 새로 왔다고 한다면. 이제 전학생을 포함해서 총 n 명의 학생을 k개의 소 그룹으로 나누는 경우를 생각하면 다음과 같다.

![image](https://user-images.githubusercontent.com/18729679/121538572-d9c13380-ca3f-11eb-8f37-af8649dc585a.png)

#### 107. 올바른 괄호 문자열(3012)의 경우 다음 원리를 생각하면 된다.

- `(?([?)]?}?`가 있을 때 첫번째 문자열 부터 끝까지 문자열 별로 dp 값을 구하며 진행한다.

> `(??)??`이란 문자열이 있을 때 문자열 i번부터 문자열 j번까지 만들 수 있는 값을 `dp[i][j]`라 정의하자
>
> - `dp[0][3] = dp[1][2]*dp[4][5]`이다.
> - 즉, 맨 처음 문자열 부터 맨 끝 문자열까지 열린 문자열과 그에 맞는 닫힌 문자열을 찾는다면 그 값은 해당 괄호 내부에서 만들 수 있는 괄호의 수 * 해당 괄호 외에서 만들 수 있는 괄호의 수이다.



#### 108. dp 재귀형식 공식같은 양식이 있으니 기억하기(팔굽혀펴기 문제)

```c++
void calculate(int i, int j) {
	if (j > N) return;
	if (dp[i][j]) return;
	dp[i][j] = true;
	for (int k = 0; k < score.size(); k++) {
        //아래처럼 재귀 형식으로 진행하면 된다.
		calculate(i + score[k], i + j + score[k]);
	}
}
```



#### 109. KMP 알고리즘은 다음과 같은 형식이다. 해당 블로그를 참조하자.

- https://gusdnd852.tistory.com/172



#### 110. `printf("%g", double_t)` 형태로 출력하면 다음과 같은 결과로 출력된다.

> 기존의 110. `printf("%f", double_t)` 형태는 double_t가 10.5이라면 `10.500000`으로 출력되지만 `"%g"`로 출력하면 뒤의 소수점의 쓸데없는 0을 제거해준다.
>
>  즉, `10.5`로 출력된다.



#### 111. setprecision함수를 사용하면 해당 자리수에서 반올림 해준다.

```c++
#include <iostream>
#include <iomanip>
 
using namespace std;
 
int main()
{
    double f = 1.23456789;
 	//5번째 소수점에서 반올림
    cout << setprecision(5) << f << endl;
    //8번째 소수점에서 반올림
    cout << setprecision(8) << f << endl;
    //10번째 소수점에서 반올림
    cout << setprecision(10) << f << endl;
 
    return 0;
}


출처: https://www.crocus.co.kr/596 [Crocus]
```

> 1.2346
>
> 1.2345678
>
> 1.2345678



#### 112. 각 자리수 별로 가능한 숫자의 합은 다음과 같이 구할 수 있다. (1089 스타트링크 타워 문제)

> 1. 만들 수 있는 총 개수를 구한다.
>
>    - 예를 들어 100의 자리에는 1,2,3 (세가지) 가 올 수 있고, 10의 자리에는 1,2 (두가지)가 올 수 있고, 1의 자리에는 1 (한가지)가 올 수 있다면, 총 만들 수 있는 수의 개수는 3 * 2 * 1 == 6가지이다.
>
> 2. 해당 자리 수 별로 값을 더한 다음 몇번 나오는지를 곱해준다.
>
>    - 예를 들어 위의 예시에는 100의 자리에는 1,2,3이 오기 때문에 100,200,300의 수가 10의자리 1의 자리를 통해 나올 수 있는 개수 만큼이 등장한다.
>
>    - 따라서, 100 + 200 + 300 = 600 이 10의 자리와 1의 자리의 종류를 통해 나올 수 있는 만큼 나온다. 
>
>      ex) 300만 따지고 본다면 위의 예시에서는 311, 312가 나올 수 있다. 즉, 300이 10의자리에서 나올 수 있는 경우의 수(2) * 1의자리에서 나올 수 있는 경우의 수(1)개 인 2*1 = 2번 나오게 된다. 
>
>    - 이 값을 구할 수 있는 방법은 만들 수 있는 총 개수 / 현재 나오는 개수이다. 현재 구하려는 자리수가 100의 자리수 이므로 만들 수 있는 총 개수 3 * 2 * 1 / 100의 자리의 경우의 수(3가지) = 6/3 = 2이다.
>
>    - 따라서 코드 형태로 만들면
>
>    ```c++
>        //만들 수 있는 숫자를 모두 더한 값
>    	double ans = 0;
>    	//만들 수 있는 총 개수
>    	double count = 1;
>    	                        
>    	//digit에는 각 자리수 별로 가능한 값이 있다.
>    	//예를 들면 N이 3일때 digit[1]에는 100이 digit[2]에는 10이 digit[3]에는 1의 자리 숫자에 나올 수 있는 값이 		들어있다. => digit[1] = {1,2,3}, digit[2] = {1,2}, digit[3] = {1}
>        for (int i = 1; i <= N; i++) {
>            count *= (double)digit[i].size();
>        }
>    	//위에서 설명한 것 처럼 현재 i번 자리수에 가능한 값을 모두 더하고(accumulate) 해당 자리수가 100의 자리인지 10의 자리인지에 따라 자리수의 값을 곱한다. 그 후 가능한 모든 경우의 수 / 현 자리수에서 가능한 경우의 수를 곱한 후 ans에 하나씩 더하면 모든 값을 구할 수 있다.
>        for (int i = 1; i <= N; i++) {
>            ans += std::accumulate(digit[i].begin(), digit[i].end(), 0) * pow(10, N - i) * (count / 			(double)digit[i].size());
>        }
>                            
>    //이를 모두 수행하면 ans에는 111 + 121 + 211 + 221 + 311 + 321이 들어가 있다.
>    ```
>
>    

#### 113.  다시 돌아오는 순열의 인덱스는 다음과 같이 작성할 수 있다.

> 1. 만약 1,2,3의 숫자가 있고, 4번 이동할때 1로 된다면, 1번에서 15번을 이동하면 다음과 15 % 3 = 0, 즉 1번에서 0번 이동함을 알 수 있다.
> 2. 만약 3번에서 14번을 이동한다면, 14 % 3 = 2, 이므로 3 + 2 = 5가 된다. 따라서 해당 값에도 % 처리를 해줘야한다.


#### 114. 회전 알고리즘은 두가지가 있다.

1. 회전을 하지만 기존의 배열은 변경되어 임의의 변경에 회전을 저장한 후 다시 받는 방법

   ```c++
   void rotate(int n){
       for(int i=0; i<n; i++){
           for(int j=0; j<n; j++){
               temp[i][j] = arr[n-1-j][i];
           }
       }
       for(int i=0; i<n; i++){
           for(int j=0; j<n; j++){
               arr[i][j] = temp[i][j];
           }
       }
   }
   ```

2. 회전을 하지만 기존의 배열은 유지하는 방법([N by N 행렬을 시계 방향 90도 회전 (tistory.com)](https://hsdevelopment.tistory.com/298))

   - 다음과 같이 바깥쪽을 최외각으로 빨간색은 파란색으로, 파란색은 노란색으로 진행하는 규칙이 있다. 따라서 맨 처음의 값만 변수에 저장하고 돌리면서 마지막에는 저장한 변수를 넣으면 된다. 

   ![image](https://user-images.githubusercontent.com/18729679/124491411-37059600-ddee-11eb-8d3b-f10c8c026f30.png)

   ```c++
   void rotate()
   {
       for (int i = 0; i < MAX / 2; i++)
           for (int j = i; j < MAX - 1 - i; j++)
           {
               int Top = arr[i][j]; // Top ← 위쪽
    
               arr[i][j] = arr[MAX - 1 - j][i]; // 위쪽 ← 왼쪽
    
               arr[MAX - 1 - j][i] = arr[MAX - 1 - i][MAX - 1 - j]; // 왼쪽 ← 아래쪽
    
               arr[MAX - 1 - i][MAX - 1 - j] = arr[j][MAX - 1 - i]; // 아래쪽 ← 오른쪽
    
               arr[j][MAX - 1 - i] = Top; // 오른쪽 ← Top(위쪽)
           }
   }
   ```

   

#### 115. x번 부터 y번 까지의 합을 메모리제이션 하고 싶다면 다음과 같이 선언하는 법이 더 빠르다.

> `dp[i][j]`의 2중 배열 구조로 선언하여 i~j까지의 dp값을 의미하는 방식으로 사용할 수도 있지만
>
> `dp[i] - dp[j]`의 배열 구조로 선언하여 0~i번 인덱스 까지의 합 - 0~j번 인덱스 까지의 합으로 선언된 배열로 구하는 방법이 메모리 할당을 낮출 수 있다.



#### 116. 다익스트라 구조는 다음과 같다. (외워두자)

```c++
std::priority_queue< std::pair<int, int>, std::vector< std::pair<int, int> >, std::greater< std::pair<int, int> > > q;
std::vector< std::vector< std::pair<int, int> > > connected;
std::vector<int> weight;

void calculate(int node) {
	q.emplace(std::make_pair(0, node));
	weight[node] = 0;

	while (!q.empty()) {
		auto front = q.top();
		q.pop();

		int cost = front.first;
		int p_node = front.second;
        
        //이미 넣어진 같은 노드라도 최단 노드가 아니라면 생략한다.
        //pq를 통해 최단 경로로 넣었더라도 만약 그 당시에는 가장 최단 경로의 가중치를 가졌다면 이미 들어가 있기 때문에 현재 cost를 확인한 뒤 더 이상 최단의 노드가 아니면 생략한다.
        if(weight[p_node] < cost) continue;

		for (int k = 0; k < connected[p_node].size(); k++) {
			int ncost = connected[p_node][k].second;
			int n_node = connected[p_node][k].first;
			
			if (weight[n_node] > cost + ncost) {
				weight[n_node] = cost + ncost;
				q.emplace(std::make_pair(weight[n_node], n_node));
			}
		}
	}
}

```

![image](https://user-images.githubusercontent.com/18729679/126642946-3851ae30-a914-472f-a23c-c5d37afbc975.png)

> - 다익스트라는 priority queue를 써야한다. 더 늦게 방문한 정점이라도 더 먼저 방문할 수 있어야하기 때문이다.
>
>   - 위의 노드를 예시로 들면 s에서 c로 가는 최단 경로는 2 + 4 + 3인 9가 정답이다.
>   - 하지만 단순히 queue를 사용하게 되면 노드의 방문 개수가 적은 s -> c의 12를 먼저 탐색하게 되므로 먼저 방문하게 된 s -> c 로부터 s -> c -> b, s-> c -> b -> a 등 최솟 값이 될 수 없는 노드를 모두 굳이 방문해서 최단경로를 찾아보게 된다.
>   - 따라서 s -> a-> b-> c는 늦게 방문하더라도 더 먼저 방문해야 나중에 s->c로 가는 가중치 12의 노선이 최단 경로가 아님을 일찍이 알아 continue문으로 생략할 수 있다.
>
>   
>
> - 하지만 priority_queue에서도 최단 경로가 아닌 내역은 분리해 생략해야한다.
>
>   - 위에서 이미 설명한 것처럼 s-> a-> b> c를 통해 알게된 최단 거리는 s->c보다 작으므로 s->c에 대해 들어있는 queue값은 생략해야한다.
>   - 따라서 `if(weight[present_node] < cost) continue`문을 넣어줘야한다.

#### 117. 다익스트라 변형 문제는 n번 노드를 꼭 방문해야하는 방식으로 정해져 있다.

- 예를 들면 T번을 꼭 방문하는 최단 경로를 찾는다면
- start번부터 T번까지의 최단 경로를 찾은 후,  end부터 T번까지를 찾아서 각각의 Weight[T] 값을 구하면 된다.



#### 118. 벨만 포드 알고리즘은 다음과 같은 원리이다.(https://ssungkang.tistory.com/entry/Algorithm-%EB%B2%A8%EB%A7%8C%ED%8F%AC%EB%93%9CBellman-Ford-%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98)

- 예를 들어 1->2를 가는데 3이고 2 -> 3을 가는데 5이고, 3 -> 1을 가는데 -6이라 가정하면 1 -> 3 번노드로 방문하는 최단 경로는 몇인가? => 3 + 5인 8이 아닌 무한히 음수에 다가간다. 3 + 5 - 6을 하면 -1이되고 즉, 1번 노드를 방문하는데 0 , -1, -2, -3, -4 ...으로 계속해서 최소값을 싸이클을 돌며 방문하는 것을 알 수 있다.

- 따라서 벨만 포드는 기존의 다익스트라와 비슷하지만 다익스트라 장점인 최적화 Priority queue를 쓰지 않으며 모든 노드를 계속 무대포로 탐색하는 방식이기에 다익스트라 보다 현저히 느리다.

- 다만 cycle의 형성을 확인할 수 있기에 음수의 가중치가진 간선의 최단 경로를 알 수 있단 장점외에는 없다.

- **반드시 노드의 길이가 N개라면 N번 탐색한다는 것을 기억해야한다.**

  

```c++
//만약 노드의 길이가 5개(N개)라면 타고갈 수 있는 간선은 1 ->2 ->3 ->4 ->5. 즉, 화살표의 개수인 4개가 최대이다.(최대 N-1번까지)
//하지만 5번이상 경로갱신을 시도했는데 갱신이 가능하다는 의미는 확실하게 cycle이 생성되었다는 의미이다.
//따라서 i == N의 의미는 cycle이 생성된 상태에서 갱신되었다는 의미이므로 cycle 값을 true로 놓으면 해당 그래프는 최단 경로가 무한한 음수에 가깝다는 것을 알 수 있다.

#include <iostream>
#include <vector>

using namespace std;

#define INF 987654321

int dist[502];
vector<pair<int,int>> v[502];

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // 정점,간선의 수
    int N,M;
    cin >> N >> M;
    
    bool cycle = false;
    
    for (int i=0;i<M;i++){
        int node1,node2,w;
        cin >> node1 >> node2 >> w;
        v[node1].push_back(make_pair(node2, w));
    }
    
    for (int i=1;i<=N;i++){
        dist[i] = INF;
    }
    
    /////////////////////////////////////////여기부터 중요/////////////////////////////////////////
    
    dist[1] = 0;
  	// 경로의 길이는 N-1 이고 N 이 된다면 음수사이클 생긴다.
    for (int i=1;i<=N;i++){
        // 모든 정점에 대해서 모든 간선을 탐색한다.
        for (int j=1;j<=N;j++){
            for (auto &n : v[j]){
              	// 방문되지 않은 지점에서 출발은 SKIP
                if (dist[j] != INF && dist[n.first]>n.second + dist[j]){
                    dist[n.first] = n.second + dist[j];
                    if (i==N) cycle = true;
                }
            }
        }
    }
    
    if (cycle) cout << "-1\n";
    else {
        for (int i=2;i<=N;i++){
            if (dist[i] == INF) cout << "-1\n";
            else cout << dist[i] << "\n";
        }
    }
}
```



#### 119. 플로이드 마샬 알고리즘(https://dongdd.tistory.com/107)

- 플로이드 마샬 알고리즘은 음수의 가중치까지도 활용할 수가 있다.

- 하지만 위의 **다익스트라와 벨만포드 알고리즘 중 가장 무대포의 알고리즘에 소스코드가 간단하기까지하다.**

- 다만 **시간 복잡도는 무려 O(N^3)에 connected를 동적이 아닌 배열로 선언하여 연결되지 않은 노드의 공간도 할당해야함으로 메모리 문제도 가지고 있다 .**

- 대신 코드는 간단하며 다익스트라의 유일한 단점인 음수의 간선을 계산할 수 있고, 현재 노드에서 한바퀴 돌아서 오는 최단 경로도 계산이 가능하며, 다익스트라처럼 한 경로에서 다른 경로들 까지의 최단 경로가 아닌 **모든 경로에서 모든 경로의 최단경로까지 계산이 가능하다.**

- **반드시 맨 위의 for문(아래 예시에서 i번 인덱스)은 중간에 방문하고자 하는 노드라는 것을 기억해야한다.**

- j부터 k까지 방문하는 노드의 최단 경로를 `dp[j][k]`라 한다면 `dp[j][k] = dp[j][i] + dp[i][k] or dp[j][k] 중 최소값`이다. 

  ```c++
  #include <iostream>
  #include <vector>
  #include <algorithm>
  using namespace std;
   
  #define INF INT_MAX
  int vertex, edge;
  int arr[100][100];
  int from, to, weight;
   
  void floyd_warshall() {
      for (int i = 1; i <= vertex; i++) {            // i vertex를 거치는 경우
          for (int j = 1; j <= vertex; j++) {        // from vertex
              for (int k = 1; k <= vertex; k++) {    // to vertex
                  if (arr[j][i] != INF && arr[i][k] != INF) {
                      arr[j][k] = min(arr[j][k], arr[j][i] + arr[i][k]);
                  }
              }
          }
      }
  }
  int main()
  {
      cin >> vertex >> edge;
      for (int i = 1; i <= vertex; i++) {        // vectex table 초기화
          for (int j = 1; j <= vertex; j++) {
              //다익스트라나 벨만 포드와 또 다른 특징은 이렇게 최단 i에서 i로 가는 경로를 지정하지 않으며 최단 경로를 갱신할 수 있다.
              //만약 1번에서 1번으로 가는 최단 경로의 사이클을 활용하지 않는 경로를 알고 싶다면, 
              //if(i==j) arr[i][i]=0;
              //을 넣으먼 되고 지금처럼 현재 노드에서 현재 노드를 다른 노드를 거쳐 싸이클 형태로 방문하는 최단 거리를 알고싶으면 위의 주석문을 넣지 않고 현재 예시 그대로 사용하면 된다.
              arr[i][j] = INF;
          }
      }
      for (int i = 0; i < edge; i++) {    // from vertex에서 to vertex 입력, 가중치 입력
          cin >> from >> to >> weight;
          arr[from][to] = weight;
      }
      floyd_warshall();
      for (int i = 1; i <= vertex; i++) {
          for (int j = 1; j <= vertex; j++) {
              cout << i << " -> " << j << "의 최단 경로 : " << arr[i][j] << endl;
          }
      }
  }
  ```



#### 120. 기존의 LIS에 비해 더 간단한 알고리즘을 빠르고, 메모리 절약적이며, 간단하게 구할 수 있다.(https://sihyungyou.github.io/baekjoon-12015/)

![image](https://user-images.githubusercontent.com/18729679/128438584-7a4af6ea-c0a3-40e5-9aeb-8b5b824d0b1a.png)

> data가 10 20 10 30 50인 값의 lis를 구해보자
>
> 1. 10은 맨처음 lis 배열에 첫번째 인덱스이므로 index배열에 1을 넣어주자
> 2. 그 다음 20은 lis 배열의 두번째 인덱스이므로 2를 넣어주자
> 3. 그 다음 10은  lower_bound에 의해 lis 배열의 첫번째 인덱스이므로 1을 넣어준다.
> 4. 그다음 30은 lis 배열의 세번째 인덱스이다.
> 5. 그다음 50은 lis 배열의 다섯번째 인덱스이다.
>
> 정리하면 lis 배열엔 1 2 1 3 4가 적혀있다.
>
> 역순으로 4 3 1 2 1순으로 정리하여 4,3,2,1에 해당하는 인덱스를 차례대로 출력하면 50 30 20 10 이 된다.
>
> 이를 역순으로 바꾸면 lis인 10 20 30 50을 구할 수 있다.
>
> - 번외로 -2 3 5 1 2 3 4의 index 배열은 1 2 3 1 2 3 4가 되는데 역순이 아니라 정방향으로 1 2 3 4를 찾으면 -2 3 5 4라는 값이 lis로 구해진다. **따라서 반드시 역순에서 진행해야한다.**

```c++
#include <iostream>
#include <vector>
#include <stack>
#include <limits.h>

//14003 가장 긴 증가하는 부분 수열 5
//굉장히 중요하다. 꼭 해당알고리즘을 기억할것
//lis 문제의 가장 효율적인 알고리즘으로
//k번째의 data에 해당하는 값이 lis 배열에서 몇번째 인덱스에 해당하는지를 적는다.
//예를 들면 10 20 10 30 20 50의 경우
//index 배열에는 1 2 1 3 2 4 순으로 저장된다.
//따라서 lis는 index의 반대 방향으로 4,3,2,1로 해당하는 값인 50 30 20 10을 역순으로 추출하면 된다.
//왜 역순으로 하고 출력하냐고 생각할 수 있는데
//-2 3 5 1 2 3 4의 index의 경우 1 2 3 1 2 3 4로 답이 -2 3 5 4라는 올바르지 않은 답안이 생성된다.
//따라서 뒤에서부터 찾아 역순으로 바꿔 출력해야한다.
long long N;
std::vector<long long> data;
std::vector<long long> lis;
std::vector<long long> index;
std::stack<long long> ans;

long long count = 0;

long long calculate() {
	lis.emplace_back(LLONG_MIN);

	for (int k = 0; k < N; k++) {
		if (lis.back() < data[k]) {
			count++;
			lis.emplace_back(data[k]);
			index[k] = (long long)lis.size() - 1;
		}
		else {
			auto itr = std::lower_bound(lis.begin(), lis.end(), data[k]);
			index[k] = (long long)std::distance(lis.begin(), itr);
			*itr = data[k];
		}
	}

	return count;
}

int main() {
	scanf("%lld", &N);
	data.assign(N, 0);
	index.assign(N, 0);
	for (int k = 0; k < N; k++) {
		scanf("%lld", &data[k]);
	}
	printf("%lld\n", calculate());

	int r_index = count;
	for (int k = N - 1; k >= 0; k--) {
		if (index[k] == r_index) {
			ans.emplace(data[k]);
			r_index--;
		}
	}

	while (!ans.empty()) {
		printf("%lld ", ans.top());
		ans.pop();
	}
}
```

>- 초기 맨 처음에 비교값을 위한 value 배열에 제일 작은 값을 넣는다.
>
>- 그 다음 모든 수열 값을 차례대로 비교하면서 lis를 갱신하면 된다.
>
>  ![image](https://user-images.githubusercontent.com/18729679/127005432-bf1ece6e-b19c-4eb6-a241-859c3935d1f0.png)
>
>-  lis 값을 계속해서 저장한 배열의 맨 뒤는 항상 이제까지의 lis 중 가장 큰 값을 가지고있다. 따라서 해당 값보다 큰 값이 들어온다면 이제까지의 lis 뒤에 붙임으로서 lis를 갱신해야한다.
>
>- 만약 현재 인덱스의 값이 현재까지의 lis의 맨 뒤보다 작다면 lower_bound를 통해 value 내에서 dp[k]보다 크면서 가장 작은 값을 찾아서 해당 값을 dp[k]로 교체해준다. (lis의 경우 길이가 같더라도 무조건 작은 차이로 연속되어 들어가야만 이후의 값들 중 작은 값이 와도 갱신이 가능하다. )


#### 121. 38번 소수 에라토스테네스 작성 코드보다 더 직관적인 알고리즘이 있어 해당 구문으로 외우는 것이 좋을 것 같다.

```c++
//is_prime[N] : 수 N은 소수인가.
int is_prime[N+1] = {true,};

void eratos() {
    //수 0과 1은 소수가 아니기 때문에
	is_prime[0] = is_prime[1] = false;

	for (int i = 2; i <= sqrt(N); i++) {
		for (int j = i * i; j <= N; j += i) {
			is_prime[j] = false;
		}
	}
}

//is_prime이 false인 것은 소수가 아니다.
```



#### 122. 부분합 문제 코드 역시 더 간단한게 있으니 다음을 참조하자.

```c++
int array[N];

void prefix_sum(int a, int b){
    //N개의 수까지 할당을 한다.
    std::vector<int> sum(N, 0);
	for (int k = 0; k < N; k++) {
		if (k == 0) sum[k] = array[k];
		else sum[k] = sum[k - 1] + array[k];
	}
    
    //a~b까지의 합
    //a가 0이면 그냥 맨 처음부터 b번 항까지의 합이므로 sum[b]이다.
    return a==0 ? sum[b]:sum[b] - sum[a-1];
}
	
```



#### 123. 이분 탐색 알고리즘은 다음과 같다. 외워두는게 좋을 듯

```c++
bool calculate(int value) {
	int begin = 0, end = N - 1;
    //begin > end이면 종료
	while (begin <= end) {
		int mid = (begin + end) / 2;
		if (A[mid] < value) {
            //수를 찾을 때 begin = mid가 아닌 +1을 한다는 점 기억
			begin = mid + 1;
		}
		else if (A[mid] > value) {
            //마찬가지로 end = mid가 아닌 -1을 한다는 점 기억
			end = mid - 1;
		}
		else return true;
	}
	return false;
}
```



#### 124.  입국심사, 풍선, 랜선자르기 문제도 꼭 이분탐색으로 어떻게 푸는지 기억할 것

- 이분탐색으로 전체 경우의 수를 대입하면서 답을 찾는 방식을 __파라메트릭 서치__라 한다.

- 브루트포스와 비슷하지만 브루트 포스는 전체를 찾는 방식이고, 파라메트릭 서치는 정렬된 와중에 전체를 찾되 이분탐색을 통해 모든 것을 찾는게 아닌 모든 경우의 수 중 가장 답에 가까운 값을 대입해 답을 찾는 것이다.

- 이분 탐색 자체가 쉬운 알고리즘이기 때문에 파라메트릭 서치 문제일 확률이 높다.

  ```c++
  #include <iostream>
  #include <vector>
  #include <algorithm>
  #include <limits.h>
  
  long long N, M;
  std::vector<long long> entrance;
  
  long long calculate() {
  	long long begin = 0;
  	long long end = entrance[N-1] * M;
  
  	long long ans = LLONG_MAX;
  
  	while (begin <= end) {
  		long long mid = (begin + end) / 2;
  		
  		long long sum = 0;
  		for (int k = 0; k < N; k++) sum += mid / entrance[k];
  
  		if (sum >= M) {
  			ans = std::min(ans, mid);
  			end = mid - 1;
  		}
  		else {
  			begin = mid + 1;
  		}
  	}
  	return ans;
  }
  
  int main() {
  	scanf("%d %d", &N, &M);
  	entrance.assign(N, 0);
  	for (int k = 0; k < N; k++) {
  		scanf("%d", &entrance[k]);
  	}
  	std::sort(entrance.begin(), entrance.end());
  	printf("%lli", calculate());
  }
  ```

  

#### 125. 이분탐색은 std::lower_bound를 사용해 풀 수 있는 문제도 이분 탐색에 포함된다.

- 이분탐색에 왜 lower_bound랑 연관있느냐를 의문에 가지겠지만 std의 lower_bound는 내부 코드가 이분탐색을 통해 가장 해당 인덱스보다 크거나 같은 값의 인덱스를 반환하는 식으로 구성되어 있다.(std::sort가 quicksort이듯이)

```c++
//개똥 벌레 문제도 다음과 같은 원리로 진행된다.
#pragma warning (disable:4996)
#include <iostream>
#include <vector>
#include <limits.h>
#include <algorithm>

std::vector<int> top;
std::vector<int> bottom;
int N, H;

std::pair<int,int> calculate() {
	int ans = INT_MAX;
	int count = 0;
	for (int k = 1; k <= H; k++) {
		int bottom_value = std::distance(std::lower_bound(bottom.begin(), bottom.end(), k), bottom.end());
		int top_value = std::distance(std::lower_bound(top.begin(), top.end(), H - k + 1), top.end());
		if (ans == bottom_value + top_value) count++;
		else if (ans > bottom_value + top_value) {
			ans = bottom_value + top_value;
			count = 1;
		}
	}
	return std::make_pair(ans, count);
}

int main() {
	scanf("%d %d", &N, &H);
	for (int k = 0; k < N; k++) {
		int value;
		scanf("%d", &value);
		if (k % 2 == 0) bottom.emplace_back(value);
		else top.emplace_back(value);
	}
	std::sort(top.begin(), top.end());
	std::sort(bottom.begin(), bottom.end());
	auto rst = calculate();

	printf("%d %d", rst.first, rst.second);
	
}
```



#### 126. 
