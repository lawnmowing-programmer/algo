# [BoJ 1920 수 찾기](https://www.acmicpc.net/problem/1920)

solved.ac Silver IV

## 카테고리

자료 구조, 정렬, 이분 탐색

## 시간복잡도

시간복잡도는 O(N + M)이다.

## 풀이

이 문제의 원래 의도는 반복되는 조회 작업의 시간을 줄이기 위해 정렬을 한번 한 다음 이분 탐색 알고리즘을 사용하는 것이다.

그러나, 이분 탐색을 이용하는 것보다 훨씬 빠르게 구현하는 다른 방법이 있다.

Python의 경우에는 set 자료구조가 hash table을 사용하기 때문에 조회에 O(1)의 시간복잡도를 가지게 된다.
Python이 아닌 다른 언어들에서는 dictionary 자료형을 사용하면 똑같은 효과를 볼 수 있다.

숫자들을 입력받아 set으로 변환해 저장을 한다. 이 과정은 N개의 숫자를 입력받을 때, O(N)의 시간복잡도를 가진다.

```python
A = set(sys.stdin.readline().split())
```

위에서 저장해 둔 set 에서 num이 존재하는지 조회를 해 그 결과를 한줄의 문자열로 합쳐서 출력한다.
이 과정은 M개의 숫자를 입력받을 때, O(M)의 시간복잡도를 가진다.

```python
sys.stdout.write('\n'.join(('1' if num in A else '0') for num in sys.stdin.readline().split()))
```

## 결과

결과 : [맞았습니다!!](http://boj.kr/6d4e050336894895993e6635fc934921)