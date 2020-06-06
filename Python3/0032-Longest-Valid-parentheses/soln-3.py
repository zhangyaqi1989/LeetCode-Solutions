class Solution:
    def longestValidParentheses(self, s: str) -> int:
        opens = []
        mx = 0
        cnt = 0
        end = -1
        for i, ch in enumerate(s):
            if ch == '(':
                opens.append(i)
            else:
                if opens:
                    left = opens.pop()
                    if opens:
                        left = opens[-1]
                    else:
                        left = end
                    mx = max(mx, i - left)
                else:
                    end = i
                    opens.clear()
        return mx
