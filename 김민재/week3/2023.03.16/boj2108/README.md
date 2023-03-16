# [BoJ 2108 통계학](https://www.acmicpc.net/problem/2108)

solved.ac Silver III

## 카테고리

수학, 구현, 정렬

## 시간복잡도

시간복잡도는 O(N)이다.

## 풀이

입력되는 정수의 범위가 -4000 ~ +4000 이기 때문에 메모라이징을 위한 8001 길이의 배열을 선언하고 입력으로부터 각 숫자의 갯수를 저장한다.

```python
nums_count = [0] * 8001
for num in sys.stdin:
    nums_count[int(num) + 4000] += 1
```

반복문을 돌면서 해당 숫자의 빈도가 0이 아닐때만 반복문 구문을 실행한다.

```python
for num, num_count in enumerate(nums_count):
    if not num_count:
        continue
```

산술 평균의 값을 구하기 위해 모든 값들을 더해준다.

```python
mean += num * num_count
```

지금까지 나온 숫자의 갯수가 입력받은 숫자의 절반이면 중앙값으로 저장한다.

```python
index += num_count
if median is None and index >= N // 2 + 1:
    median = num
```

숫자의 빈도가 가장 높은 값을 최빈값으로 저장한다. 만약 같은 최빈값이 여러번 나온다면, 두번째로 만난 최빈값을 그 결과로 선택한다.

```python
if max_count < num_count:
    max_count = num_count
    second_mode = False
    mode = num
elif max_count == num_count and not second_mode:
    second_mode = True
    mode = num
```

최소값과 최대값을 저장한다.

```python
min_num = min(min_num, num)
max_num = max(max_num, num)
```

산술평균을 구하기 위해 전체 합을 입력받은 숫자의 갯수로 나누어 준다. 범위를 구하기 위해 최대값에서 최소값을 뺀다.

```python
mean /= N
delta = max_num - min_num
```

산술평균의 출력 포멧을 맞추기 위해 소수점 이하 첫째 자리에서 반올림을 해준다.

```python
sys.stdout.write('\n'.join(map(str, [round(mean), median, mode, delta])))
```

## 결과

결과 : [맞았습니다!!](http://boj.kr/438516030e074515b6465e057f5f2c1d)