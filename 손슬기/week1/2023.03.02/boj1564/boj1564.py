N = int(input())
f = 1
for i in range(1, N+1):
    f *= i
    while True:
        if str(f)[-1] == "0":
            f //=10
        else:
            break
    f%=100000000000000000
print(str(f)[-5:])
