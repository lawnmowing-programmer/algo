from collections import deque

def solution(nums:deque):
    while len(nums) != 1:
        nums.popleft()
        nums.append(nums.popleft())
    return (nums.pop())

N = int(input())
nums = deque([i for i in range(1, N + 1)])
print(solution(nums))