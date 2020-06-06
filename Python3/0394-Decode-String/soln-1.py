class Solution:
    def decodeString(self, s: str) -> str:
        stack = [[1, ""]]
        num = 0
        for ch in s:
            if ch.isdigit():
                num = num * 10 + int(ch)
            elif ch.isalpha():
                stack[-1][-1] += ch
            elif ch == '[':
                stack.append([num, ""])
                num = 0
            else:
                cnt, chars = stack.pop()
                stack[-1][-1] += chars * cnt
        return stack[-1][-1]
