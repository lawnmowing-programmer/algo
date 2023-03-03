def is_prime(n):
    if n < 2:
        return False
    elif n == 2 or n == 3:
        return True
    if n % 2 == 0 or n % 3 == 0:
        return False
    for i in range(5, n // 5, 2):
        if n % i == 0:
            return False
    return True

def solution(nums):
    res = 0
    for num in nums:
        if is_prime(num):
            res += 1
    return (res)

N = int(input())
nums = list(map(int, input().split()))
print(solution(nums))