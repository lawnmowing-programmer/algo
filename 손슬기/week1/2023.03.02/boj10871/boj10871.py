N, X = map(int, input().split())
n = list(map(int, input().split()))
    
for i in range(0, N):
    if n[i] < X:
        print(n[i], end = ' ')