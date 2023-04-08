# [BoJ 2839 설탕 배달](https://www.acmicpc.net/problem/2839)

solved.ac Silver IV

## 카테고리

수학, 다이나믹 프로그래밍, 그리디 알고리즘

## 시간복잡도

시간복잡도는 O(1)이다.

## 풀이

설탕의 무게를 5로 나눌 수 있을 때 바로 결과를 출력 해준다.

```python
if sugar % 5 == 0:
    sys.stdout.write(str(sugar // 5))
```

5로 나눌 수 없으면, 5로 나눈 나머지가 3으로 나누어지는지 확인하기 위해, 5로 나눈 몫과 나머지를 저장한다.

```python
else:
    bags_of_5kg = sugar // 5
    remaining_sugar = sugar % 5
```

5로 나눠지지 않는 경우의 나머지는 1~4 이기 때문에 그중 3으로 바로 나눠지는 3을 제외하면 1,2,4가 남는다.
이 세 경우는 5를 최대 2번만 더해주면 3으로 나눌 수 있기 때문에, 5로 나눈 몫만큼 전부 계산해 줄 필요가 없다.
3번을 반복하며 3으로 나눠지면 총 가방 개수를, 안나눠지면 -1을 출력해준다.

```python
for _ in range(3):
    if remaining_sugar % 3 == 0:
        bags_of_3kg = remaining_sugar // 3
        sys.stdout.write(str(bags_of_5kg + bags_of_3kg))
        break
    remaining_sugar += 5
    bags_of_5kg -= 1
    if bags_of_5kg < 0:
        sys.stdout.write("-1")
        break
```

## 결과

결과 : [맞았습니다!!](http://boj.kr/58be9e15f7e34ed1b4c9adccf3e065d7)
