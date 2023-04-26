# [BoJ 10250 ACM 호텔](https://www.acmicpc.net/problem/10250)

solved.ac Bronze III

## 카테고리

수학, 구현, 사칙연산

## 시간복잡도

각 테스트케이스에 대한 시간복잡도는 O(1)이다.

## 풀이

입력을 전처리하는 단계이다.

우선, EOF까지 입력을 받아 첫 라인을 제외하고 줄 단위로 나눠 배열을 만들어 준다.
그 후, 각 줄별로 스페이스 기준으로 split 후 int로 타입캐스팅해서 저장한다.

```python
testcases = [list(map(int, testcase.split())) for testcase in sys.stdin.read().splitlines()[1:]]
```

테스트케이스별로 div와 mod 연산을 통해 목표값을 계산해서 결과 리스트를 만드는 단계이다.

```python
result = [str(((testcase[2] - 1) % testcase[0] + 1) * 100 + (testcase[2] - 1) // testcase[0] + 1) for testcase in testcases]
```

결과를 개행을 구분자로 하나의 문자열로 합쳐 출력해준다.

```python
sys.stdout.write('\n'.join(result))
```

## 결과

결과 : [맞았습니다!!](http://boj.kr/602b2e12b41b4a31a26db4bd59d4f34e)
