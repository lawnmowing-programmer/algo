import sys

N = int(sys.stdin.readline())

nums_count = [0] * 8001
for num in sys.stdin:
    nums_count[int(num) + 4000] += 1

index = mean = max_count = 0
second_mode = False
min_num, max_num = 4001, -4001
median = None

for num, num_count in enumerate(nums_count):
    if not num_count:
        continue
    num -= 4000

    mean += num * num_count

    index += num_count
    if median is None and index >= N // 2 + 1:
        median = num

    if max_count < num_count:
        max_count = num_count
        second_mode = False
        mode = num
    elif max_count == num_count and not second_mode:
        second_mode = True
        mode = num

    min_num = min(min_num, num)
    max_num = max(max_num, num)

mean /= N
delta = max_num - min_num

sys.stdout.write('\n'.join(map(str, [round(mean), median, mode, delta])))
