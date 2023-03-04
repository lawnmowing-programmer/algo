# [BoJ 1874 스택 수열](https://www.acmicpc.net/problem/1874)

solved.ac Silver II

## 카테고리

자료 구조, 스택

## 시간복잡도

시간복잡도는 O(n)이다.

## 풀이

BoJ 1874에서 의외로 시간 문제가 발생하는 부분이다.

테스트 케이스의 길이가 상당히 길기 때문에 한번에 입력을 받아준다.

```python
n, *nums = map(int, sys.stdin.buffer.read().splitlines())
```

1부터 시작해서 직접 스택에 집어 넣으면서 실제로 가능한 순서인지 체크를 한다.

pop을 했을 때 나오는 숫자가 다르면 기록했던 오퍼레이터들을 지워준다.

```python
count = 1
stack = []
stack_operator = []
for stack_pop_num in nums:
    while count <= stack_pop_num:
        stack.append(count)
        stack_operator.append("+")
        count += 1

    if stack.pop() != stack_pop_num:
        stack_operator.clear()
        break
    stack_operator.append("-")
```

오퍼레이터 기록이 존재하면 기록을, 존재하지 않는다면 불가능한 입력이기 때문에 ``"NO"``를 출력한다.

```python
sys.stdout.write('\n'.join(stack_operator) if stack_operator else "NO")
```

## 결과

결과 : [맞았습니다!!](http://boj.kr/79719371c3d44dac8bd619a5c2bf9da2)