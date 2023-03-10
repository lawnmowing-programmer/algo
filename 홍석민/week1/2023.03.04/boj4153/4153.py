def solution(x: int, y: int, z: int):
    if z ** 2 == x ** 2 + y ** 2:
        print("right")
    else:
        print("wrong")

while True:
    nums = list(map(int, input().split()))
    if sum(nums) == 0:
        break
    num = max(nums)
    nums.remove(num)
    solution(nums[0], nums[1], num)
