import sys

N = int(sys.stdin.readline())
nums = list(map(int, sys.stdin.readline().split()))
max_num = max(nums)

eratosthenes = [False] + [True] * (max_num - 1)

for i in range(2, int(max_num ** 0.5) + 1):
    if eratosthenes[i - 1]:
        for non_prime_num in range(2, max_num // i + 1):
            eratosthenes[i * non_prime_num - 1] = False

sys.stdout.write(str(sum(1 for num in nums if eratosthenes[num - 1])))
