N  = int(input())
sum_a = 0
for i in range(N):
    s, a = map(int, input().split())
    sum_a += a%s
print(sum_a)
#처음에 이렇게 제출했을 때는 부분점수 받음. 굳이 apple이라는 list를 만들 필요가 없었다. 
# N  = int(input())
#for i in range(N):
#    s, a = map(int, input().split())
#    apple = []
#    if a%s == 0:
#        print(0)
#    else:
#        apple.append(a%s)
#        print(sum(apple))