class Solution:
    def addBinary(self, a: str, b: str) -> str:
        ans = ""
        i, j, up = len(a) - 1, len(b) - 1, 0
        while i >= 0 or j >= 0:
            sum = up
            sum, i = sum + int(a[i]) if i >= 0 else sum + 0, i - 1
            sum, j = sum + int(b[j]) if j >= 0 else sum + 0, j - 1
            up = 1 if sum > 1 else 0
            ans = str(sum % 2) + ans
        ans = '1' + ans if up else ans
        return (ans)