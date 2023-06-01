# [BoJ 11651 좌표 정렬하기 2](https://www.acmicpc.net/problem/11651)

solved.ac Silver V

## 카테고리

정렬

## 시간복잡도

시간복잡도는 O(n log n)이다.

## 풀이

입력 받은 데이터들을 zip을 이용해 튜플로 묶어준 다음 다중 key를 지정해서 정렬을 수행한다.

```python
inputs = sys.stdin.read().split()[1:]
pos = sorted(zip(inputs[::2], inputs[1::2]), key=lambda x: (int(x[1]), int(x[0])))
```

format를 이용해 출력 형식을 맞춰서 출력해준다.

```python
sys.stdout.write('\n'.join('{} {}'.format(*p) for p in pos))
```

## 결과

결과 : [맞았습니다!!](http://boj.kr/a9b6e37cbdd84a87a83eff8d0c3cab83)