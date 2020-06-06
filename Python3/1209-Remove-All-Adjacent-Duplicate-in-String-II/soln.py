class Solution:
    def removeDuplicates(self, s: str, k: int) -> str:
        stack = []
        for ch in s:
            if not stack or stack[-1][0] != ch:
                stack.append([ch, 1])
            else:
                stack[-1][-1] = (stack[-1][-1] + 1) % k
                if stack[-1][-1] == 0:
                    stack.pop()
        return ''.join(ch * cnt for ch, cnt in stack)
