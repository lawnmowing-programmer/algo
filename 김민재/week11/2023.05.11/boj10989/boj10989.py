import sys

nums = [0] * 10000

for _ in range(int(sys.stdin.readline())):
    nums[int(sys.stdin.readline()) - 1] += 1

for num, count in enumerate(nums):
    for _ in range(count):
        sys.stdout.write(str(num + 1) + '\n')
