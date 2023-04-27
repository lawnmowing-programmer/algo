# [BoJ 4949 균형잡힌 세상](https://www.acmicpc.net/problem/4949)

solved.ac Silver IV

## 카테고리

자료 구조, 문자열, 스택

## 시간복잡도 / 공간복잡도

N은 입력 라인 수이고 M은 입력 라인의 최대 길이 일 때, 시간복잡도는 O(N * M)이고, 공간복잡도는 O(N * M) 이다.

## 풀이

EOF까지 입력을 받아 마지막 라인을 제외하고 줄 단위로 나눠 배열을 만들어 준다.

```python
inputs = sys.stdin.read().splitlines()[:-1]
```

매칭되는 괄호들을 저장하는 dictionary를 만들어준다.

```python
BRACKET_MAP = {'(': ')', '[': ']'}
```

각각의 라인에 대해 괄호의 갯수가 동일하지 않으면 결과에 no를 추가하고 다음줄로 넘어간다.

```python
for line in inputs:
    if line.count('(') != line.count(')') or line.count('[') != line.count(']'):
        result.append("no")
        continue
```

라인의 각 문자에 대해 여는 괄호에 해당한다면 스택에 추가하고 닫는 괄호에 해당한다면 스택과 괄호를 비교해 일치하는지 여부를 확인한다.

```python
is_balanced = True
for char in line:
    if char in BRACKET_MAP:
        stack.append(char)
    elif char in BRACKET_MAP.values() and stack and BRACKET_MAP[stack.pop()] != char:
        is_balanced = False
        break
```

플래그와 스택에 남아있는 괄호가 있는지의 여부에 따라 결과를 추가해준다.

```python
result.append("yes" if is_balanced and not stack else "no")
```

결과를 하나의 문자열로 만들어 출력한다.

```python
sys.stdout.write('\n'.join(result))
```

## 결과

결과 : [맞았습니다!!](http://boj.kr/fc04b1b0c0bc4e489e1bef54b4855da6)
