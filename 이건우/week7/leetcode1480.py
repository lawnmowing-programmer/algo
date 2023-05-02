class Solution(object):
    def runningSum(self, nums):
        return [sum(nums[:i+1]) for i in range(len(nums))]