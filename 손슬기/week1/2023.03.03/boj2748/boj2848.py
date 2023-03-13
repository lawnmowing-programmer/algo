N = int(input())
f = []
n = 0
for i in range(N+1):
    if i == 0:
        n = 0
    elif i <= 2:
        n = 1
    else:
        n = f[-1]+f[-2]
    f.append(n)
print(f[-1])
#0과 1로 시작하는 걸 따로 앞에 빼주고, 그 다음 수부터는 앞+앞앞수를 더해줘서 구했다.