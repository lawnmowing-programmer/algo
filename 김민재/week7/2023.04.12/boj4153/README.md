# [BoJ 4153 직각삼각형](https://www.acmicpc.net/problem/4153)

solved.ac Bronze III

## 카테고리

수학, 기하학, 피타고라스 정리

## 시간복잡도

시간복잡도는 O(N)이다.

## 풀이

입력을 전처리하는 단계이다.

우선, EOF까지 입력을 받아 마지막 라인을 제외하고 줄 단위로 나눠 배열을 만들어 준다.
그 후, 각 줄별로 스페이스 기준으로 split 후 제곱을 하고 정렬을 수행한다.

최종적으로 입력받은 값들을 제곱하고 정렬한 2차원 배열을 만든다.

```python
inputs = [sorted(map(lambda y: pow(int(y), 2), x.split())) for x in sys.stdin.read().splitlines()[:-1]]
```

전처리 된 데이터를 처리하는 단계이다.

전처리 한 데이터를 연산해 피타고라스의 정리에 부합하면 right를, 부합하지 않으면 wrong을 결과 문자열에 넣는다.

```python
result = ["right" if sum(triangle[:2]) == triangle[2] else "wrong" for triangle in inputs]
```

결과를 개행을 구분자로 하나의 문자열로 합쳐 출력해준다.

```python
sys.stdout.write('\n'.join(result))
```

## 결과

결과 : [맞았습니다!!](http://boj.kr/9dded98a98574282b74e937238cdd4b4)
