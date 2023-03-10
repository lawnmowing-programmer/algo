## [BOJ 1947 선물 전달](https://www.acmicpc.net/problem/1947)

### 카테고리

다이나믹 프로그래밍

### 시간복잡도

O\(N\)

### 풀이

해당 문제를 접했을 때 가장 먼저 완전탐색 방법이 떠오를 것이다.  
완전탐색으로 서로 다른 사람에게 서로 다른 선물을 전달하려면 매 탐색마다 N-1 개의 선물을 가지는 경우를 고려해야 하므로 시간복잡도가 N의 N승이 된다.  
N의 범위가 1'000'000이기 때문에 해당 방법으로는 해결이 불가능하다.  
그렇다면 어떻게 해야 시간을 단축할 수 있을까?  
일단 N이 3, 4, 5일때의 발생할 수 있는 경우의 수를 모두 찍어보았다.

```cpp
// N이 3일 때
2 3 1
3 1 2
// N이 4일 때
2 1 4 3
2 3 4 1
2 4 1 3
3 1 4 2
3 4 1 2
3 4 2 1
4 1 2 3
4 3 1 2
4 3 2 1
// N이 5일 때
2 1 4 5 3
2 1 5 3 4
2 3 1 5 4
2 3 4 5 1
2 3 5 1 4
2 4 1 5 3
2 4 5 1 3
2 4 5 3 1
2 5 1 3 4
2 5 4 1 3
2 5 4 3 1
3 1 2 5 4
3 1 4 5 2
3 1 5 2 4
3 4 1 5 2
3 4 2 5 1
3 4 5 1 2
3 4 5 2 1
3 5 1 2 4
3 5 2 1 4
3 5 4 1 2
3 5 4 2 1
4 1 2 5 3
4 1 5 2 3
4 1 5 3 2
4 3 1 5 2
4 3 2 5 1
4 3 5 1 2
4 3 5 2 1
4 5 1 2 3
4 5 1 3 2
4 5 2 1 3
4 5 2 3 1
5 1 2 3 4
5 1 4 2 3
5 1 4 3 2
5 3 1 2 4
5 3 2 1 4
5 3 4 1 2
5 3 4 2 1
5 4 1 2 3
5 4 1 3 2
5 4 2 1 3
5 4 3 2 1
```

출력된 수를 유심히 보다보면 한가지 규칙을 볼 수 있다.  
N이 5일때를 한번 살펴보자.  
앞자리가 i일때의 수를 k\[i\]라고 할 때, k\[i\]는 각각 11이다.  
즉, N이 5일때의 앞자리에 올 수 있는 수는 5-1개가 있으므로 답은 11 \* \(5-1\)이 된다.  
그렇다면 저 11이라는 숫자는 어디서 나온것일까?

```cpp
// 앞자리가 2일때
2 1 4 5 3
2 1 5 3 4
2 3 1 5 4
2 3 4 5 1
2 3 5 1 4
2 4 1 5 3
2 4 5 1 3
2 4 5 3 1
2 5 1 3 4
2 5 4 1 3
2 5 4 3 1
```

N이 5이고, 앞자리가 2일때의 경우의 수이다.
해당 경우의 수에서 두번째 자리가 1일때를 한번 생각해보자.  
1과 2에게 선물을 주고나면, 나머지 3,4,5에게 선물을 주는것은 3명에게 서로 다른 사람의 선물을 주는 것과 같은 경우가 된다.  
그렇다면 두번째 자리에 1이 오지 않는 경우의 수를 생각해보자.  
해당 경우의 수는 그냥 4명에게 서로 다른 사람의 선물을 주는것과 같은 경우이다.  
왜냐하면 2번째 사람이 받을 수 있는 선물은 (3,4,5), 3번째 사람이 받을 수 있는 선물은 (1,4,5), 4번째는 (1,3,5), 5번째는 (1,3,4)로, 4명의 사람이 서로 다른 3명의 선물을 받는 경우의 수가 되기 때문이다.  
즉, 11이라는 수는 N이 3일때의 수 + N이 4일때의 수 = 2 + 9 = 11이라는 과정을 거쳐서 나온 것이다.  
따라서 N일때의 답이 dp\[N\]이라고 할 때, dp\[N\] = \(dp\[N-1\] + dp\[N-2\]\) \* \(N-1\)이라는 점화식을 세울 수 있다.

### 결과

[맞았습니다!!](https://www.acmicpc.net/source/share/aae8fbd07dac411b86e87dfa80a21665)
