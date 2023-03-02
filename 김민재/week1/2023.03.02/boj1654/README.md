# [BoJ 1654 랜선 자르기](https://www.acmicpc.net/problem/1654)

solved.ac Silver II

## 카테고리

이분 탐색, 매개 변수 탐색

## 시간복잡도

시간복잡도는 O(log n)이다.

## 풀이

단일 랜선의 최소 길이인 1과 최대 길이인 보유중인 랜선 중 가장 긴 랜선 길이의 중간값으로 만들 수 있는 랜선 갯수를 기준으로 이분탐색을 진행한다.

```python
min_cable_length = 1
max_cable_length = max(cables)

while min_cable_length <= max_cable_length:
    mid_cable_length = (min_cable_length + max_cable_length) // 2

    if sum(map(lambda x: x // mid_cable_length, cables)) >= N:
        min_cable_length = mid_cable_length + 1
    else:
        max_cable_length = mid_cable_length - 1
```

이분탐색 완료 후, `max_cable_length`이 가능한 가장 긴 길이가 된다.

```python
sys.stdout.write(str(max_cable_length))
```

## 결과

결과 : [맞았습니다!!](http://boj.kr/afa3978ef30b42e4a1233c7c12bdbf3c)