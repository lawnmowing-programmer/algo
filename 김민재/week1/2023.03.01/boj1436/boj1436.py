import sys

N = int(sys.stdin.readline())

count = 0
for i in range(N):
    if i % 1000 == 666:
        for j in range(1000):
            count += 1
            if count == N:
                sys.stdout.write(str(i * 1000 + j))
                exit()
    elif i % 100 == 66:
        for j in range(100):
            count += 1
            if count == N:
                sys.stdout.write(str(i * 1000 + 600 + j))
                exit()
    elif i % 10 == 6:
        for j in range(10):
            count += 1
            if count == N:
                sys.stdout.write(str(i * 1000 + 660 + j))
                exit()
    else:
        count += 1
        if count == N:
            sys.stdout.write(str(i * 1000 + 666))
            exit()
