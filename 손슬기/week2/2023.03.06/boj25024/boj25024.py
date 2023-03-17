import sys
T = int(input())
m31 = [1, 3, 5, 7, 8, 10, 12] #31일까지인 달
m30 = [4, 6, 9, 11] #30일까지인 달
for i in range(T):
    times = 'No'
    days = 'No'
    a, b = map(int, sys.stdin.readline().split())
    if(a>0 and a<=12):
        if(a in m31 and 0 < b <= 31):
            days = 'Yes'
        elif(a in m30 and 0 < b <= 30):
            days = 'Yes'
        elif(a == 2 and 0 < b <=29):
            days = 'Yes'
    if(0 <= a <=23):
        if(b <= 59):
            times = 'Yes'
    print(times, days)
    #참고: https://maeseok.tistory.com/51
    