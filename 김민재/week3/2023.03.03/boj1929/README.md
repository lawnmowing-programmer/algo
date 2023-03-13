# [BoJ 1978 소수 찾기](https://www.acmicpc.net/problem/1978)

solved.ac Silver V

## 카테고리

수학, 정수론, 소수 판정, 에라토스테네스의 체

## 시간복잡도

시간복잡도는 O(Nlog(log(N)))이다.

## 풀이

에라토스테네스의 체의 결과를 저장할 배열을 선언한다. 1은 항상 소수가 아니기 때문에 False로 두고 시작한다.

```python
max_num = max(nums)

eratosthenes = [False] + [True] * (max_num - 1)
```

``sqrt(max_num)``까지 반복하며 배수가 되는 수들을 ``False``로 바꿔준다.

```python
for i in range(2, int(max_num ** 0.5) + 1):
    if eratosthenes[i - 1]:
        for non_prime_num in range(2, max_num // i + 1):
            eratosthenes[i * non_prime_num - 1] = False
```

입력 받은 수들을 에라토스테네스의 체에 걸러진 숫자들과 비교해 소수의 개수를 구한다

```python
sys.stdout.write(str(sum(1 for num in nums if eratosthenes[num - 1])))
```

## 결과

결과 : [맞았습니다!!](http://boj.kr/d6854dcc483d487398d4be75a63d2543)