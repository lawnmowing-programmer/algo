class Solution:
    def mySqrt(self, x: int) -> int:
        ans = 1
        while ans * ans <= x:
            ans += 1
        return (ans - 1)