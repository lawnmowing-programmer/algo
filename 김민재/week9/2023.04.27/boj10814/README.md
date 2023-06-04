# [BoJ 10814 나이순 정렬](https://www.acmicpc.net/problem/10814)

solved.ac Silver V

## 카테고리

정렬

## 시간복잡도

시간복잡도는 평균적으로 O(n log n)이다.

## 풀이

입력받은 사용자들의 첫번째 항목을 키로 사용해서 오름차순으로 정렬한다.

```python
users = sorted(users, key=lambda x: int(x.split()[0]))
```

## 결과

결과 : [맞았습니다!!](http://boj.kr/751061745e4b48569e1dd2b0f3e9851f)
