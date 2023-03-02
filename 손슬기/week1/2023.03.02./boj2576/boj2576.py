n_list = []
for i in range(7):
    n = int(input())
    if n % 2 == 1:
        n_list.append(n)
n_list.sort()
if n_list:
    print(sum(n_list))
    print(n_list[0])
else:
    print(-1)