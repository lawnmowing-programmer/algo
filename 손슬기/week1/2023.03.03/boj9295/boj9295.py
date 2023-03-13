T = int(input())
for i in range(1,T+1):
    a, b = map(int,input().split())
    print('Case',str(i)+':',a+b)
    #숫자를 문자열로 출력하기 위해 str(i)로 출력