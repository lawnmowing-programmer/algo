import sys

M, N = map(int, sys.stdin.readline().split())

eratosthenes = [False] + [True] * (N - 1)

for i in range(2, int(N ** 0.5) + 1):
    if eratosthenes[i - 1]:
        for non_prime_num in range(2, N // i + 1):
            eratosthenes[i * non_prime_num - 1] = False

sys.stdout.write('\n'.join([f'{i + M}' for i, is_prime in enumerate(eratosthenes[M - 1:]) if is_prime]))
