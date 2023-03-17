import sys
n = int(sys.stdin.readline())
for i in range(1, n+1):
    a, b = map(int, input().split())
    print('Case #'+str(i)+':', a+b)
    #print(f'Case #{i}: {a+b}') 해도 됨
    