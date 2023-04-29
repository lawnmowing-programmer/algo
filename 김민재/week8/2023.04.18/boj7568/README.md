# [BoJ 7568 덩치](https://www.acmicpc.net/problem/7568)

solved.ac Silver V

## 카테고리

구현, 브루트포스 알고리즘

## 시간복잡도

시간복잡도는 O(n^2)이고, 공간복잡도는 O(n)이다.

## 풀이

입력을 전처리해주는 단계.
2차원 배열로 만들어준다.

```python
size = [list(map(int, x.split())) for x in sys.stdin.read().splitlines()[1:]]
```

normal의 해법.
배열 슬라이싱을 이용해 불필요한 반복 비교를 줄여준다.

```python
for i, person in enumerate(size[:-1]):
    for j, comparison in enumerate(size[i+1:]):
        if person[0] > comparison[0] and person[1] > comparison[1]:
            result[i + j + 1] += 1
        elif person[0] < comparison[0] and person[1] < comparison[1]:
            result[i] += 1
```

pythonic의 해법.
비교 결과들을 bool 형태로 저장하는 배열을 구한 뒤, sum 함수를 이용해 그 합을 저장한다.

```python
compare = [sum([person1[0] < person2[0] and person1[1] < person2[1] for person2 in size]) for person1 in size]
sys.stdout.write(' '.join([str(rank + 1) for rank in compare]))
```

## 결과

normal 결과 : [맞았습니다!!](http://boj.kr/58ddc94e98c74696a8e16c8c08aa1d20)
pythonic 결과 : [맞았습니다!!](http://boj.kr/908667949c2547a983ed4b521cb1cd27)
