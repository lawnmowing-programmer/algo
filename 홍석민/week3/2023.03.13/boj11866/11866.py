from collections import deque

def solution(circle: deque, K: int):
    counter = 0
    while circle:
        counter += 1
        if counter % K == 0:
            print(circle.popleft(), end='')
            if circle:
                print(', ', end='')
        else:
            circle.append(circle.popleft())

N, K = map(int, input().split())
circle = deque([i for i in range(1, N + 1)])
print('<', end='')
solution(circle, K)
print('>')
