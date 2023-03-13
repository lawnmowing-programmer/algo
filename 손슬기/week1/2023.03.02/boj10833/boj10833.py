N  = int(input())
sum_a = 0
for i in range(N):
    s, a = map(int, input().split())
    sum_a += a%s
print(sum_a)