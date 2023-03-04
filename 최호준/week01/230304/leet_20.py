"""
   시간 복잡도: O(n)
"""
class Solution:
    def isValid(self, s: str) -> bool:
        stack = []
        pair = {'}': '{', ']': '[', ')': '('}
        for c in s:
            if c in [')', '}', ']']:
                if not stack or stack[-1] is not pair[c]:
                    return False
                stack.pop()
            else: 
                stack.append(c)
        return len(stack) == 0 

x = Solution()
print(x.isValid( "()[]{}"))
print(x.isValid("[)"))
