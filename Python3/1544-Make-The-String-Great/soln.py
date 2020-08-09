class Solution:
    def makeGood(self, s: str) -> str:
        stack = []
        DIFF = abs(ord('a') - ord('A'))
        for ch in s:
            if stack and abs(ord(stack[-1]) - ord(ch)) == DIFF:
                stack.pop()
            else:
                stack.append(ch)
        return ''.join(stack)
