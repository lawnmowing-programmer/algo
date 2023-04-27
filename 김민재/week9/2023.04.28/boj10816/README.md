# [BoJ 10816 숫자 카드 2](https://www.acmicpc.net/problem/10816)

solved.ac Silver IV

## 카테고리

자료 구조, 정렬, 이분 탐색, 해시를 사용한 집합과 맵

## 시간복잡도

시간복잡도는 n은 카드 수이고 m은 예측 수일 때 O(n + m)이다.

## 풀이

collections 모듈의 Counter를 사용해 카드의 갯수 dictionary를 만들어준다.

```python
card_count = Counter(cards)
```

dictionary에서 개수를 검색해서 출력해준다.

```python
sys.stdout.write(' '.join(str(card_count[prediction]) for prediction in predictions))
```

## 결과

결과 : [맞았습니다!!](http://boj.kr/251a9c5a5f2b40578b061724193cbbfa)
