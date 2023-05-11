# [BoJ 10989 수 정렬하기 3](https://www.acmicpc.net/problem/10989)

solved.ac Bronze I

## 카테고리

정렬

## 시간복잡도

시간복잡도는 O(n)이다.

## 풀이

입력값의 개수가 입력값의 범위보다 압도적으로 크기 때문에, 메모이제이션 기법을 사용해 입력받은 숫자들의 개수를 저장한다.

```python
nums = [0] * 10000

for _ in range(int(sys.stdin.readline())):
    nums[int(sys.stdin.readline()) - 1] += 1
```

메모이제이션 기법을 이용해 저장한 숫자들을 앞에서부터 출력한다.

```python
for num, count in enumerate(nums):
    for _ in range(count):
        sys.stdout.write(str(num + 1) + '\n')
```

## 결과

결과 : [맞았습니다!!](http://boj.kr/557616d0775c49999c0f2281eb010cc3)
