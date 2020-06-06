class Solution:
    def reverseParentheses(self, s: str) -> str:
        stack = [[]]
        for ch in s:
            if ch.isalpha():
                stack[-1].append(ch)
            elif ch == '(':
                stack.append([])
            else:
                item = ''.join(stack.pop())[::-1]
                stack[-1].append(item)
        return ''.join(stack[0])
