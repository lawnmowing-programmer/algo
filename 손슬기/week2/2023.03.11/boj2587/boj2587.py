#첫째 줄부터 다섯 번째 줄까지 한 줄에 하나씩 자연수가 주어진다. 주어지는 자연수는 100 보다 작은 10의 배수이다.
#첫째 줄에는 평균을 출력하고, 둘째 줄에는 중앙값을 출력한다. 평균과 중앙값은 모두 자연수이다.
n_list = []
for i in range(5):
    n_list.append(int(input()))
n_list.sort()
print(int(sum(n_list)/5))
print(n_list[2])

