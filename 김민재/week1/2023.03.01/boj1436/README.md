# [BoJ 1436 영화감독 숌](https://www.acmicpc.net/problem/1436)

solved.ac Silver V

## 카테고리

브루트포스 알고리즘

## 시간복잡도

시간복잡도는 O(N)이다.

## 풀이

조건에 부합하는 숫자를 순서대로 만들어 N번째에 출력 후 종료한다.

```python
count = 0
for i in range(N):
    if i % 1000 == 666:
        for j in range(1000):
            count += 1
            if count == N:
                sys.stdout.write(str(i * 1000 + j))
                exit()
    elif i % 100 == 66:
        for j in range(100):
            count += 1
            if count == N:
                sys.stdout.write(str(i * 1000 + 600 + j))
                exit()
    elif i % 10 == 6:
        for j in range(10):
            count += 1
            if count == N:
                sys.stdout.write(str(i * 1000 + 660 + j))
                exit()
    else:
        count += 1
        if count == N:
            sys.stdout.write(str(i * 1000 + 666))
            exit()
```

## 결과

결과 : [맞았습니다!!](http://boj.kr/3c8a25df0f4b4efe9e71f1040b47b260)