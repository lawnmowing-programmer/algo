# [BoJ 1929 소수 구하기](https://www.acmicpc.net/problem/1929)

solved.ac Silver III

## 카테고리

수학, 정수론, 소수 판정, 에라토스테네스의 체

## 시간복잡도

시간복잡도는 O(Nlog(log(N)))이다.

## 풀이

에라토스테네스의 체의 결과를 저장할 배열을 선언한다. 1은 항상 소수가 아니기 때문에 False로 두고 시작한다.

```python
eratosthenes = [False] + [True] * (N - 1)
```

``sqrt(N)``까지 반복하며 배수가 되는 수들을 ``False``로 바꿔준다.

```python
for i in range(2, int(N ** 0.5) + 1):
    if eratosthenes[i - 1]:
        for non_prime_num in range(2, N // i + 1):
            eratosthenes[i * non_prime_num - 1] = False
```

에라토스테네스의 체에 의해 걸러진 결과 중, 입력 받은 범위의 소수들을 출력한다.

```python
sys.stdout.write('\n'.join([f'{i + M}' for i, is_prime in enumerate(eratosthenes[M - 1:]) if is_prime]))
```

## 결과

결과 : [맞았습니다!!](http://boj.kr/2270c2f70d7044d7bd44c93173e6d3d2)