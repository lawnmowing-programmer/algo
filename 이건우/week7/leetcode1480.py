class Solution(object):
    def runningSum(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        res = []
        sums = 0
        for _ in nums:
            sums += _
            res.append(sums)
        return res