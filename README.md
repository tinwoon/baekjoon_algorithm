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
- 이때 위처엄 inorder의 begin, inorder의 end, postorder의 begin, postorder의 end 처럼 구현하는 이유는 각각의 순회별로 왼쪽노드의 크기와 오른쪽 노드의 크기, 그리고 그 노드의 root값을 알기 위함이다.

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

