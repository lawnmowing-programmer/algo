import sys
n = int(sys.stdin.readline())
cnt = 0
while n > 0:
    if n % 5 == 0:
        cnt += n // 5
        n = 0
        break
    else:
        n -= 2
        cnt += 1
if n == 0:
    print(cnt)
else:
    print(-1)