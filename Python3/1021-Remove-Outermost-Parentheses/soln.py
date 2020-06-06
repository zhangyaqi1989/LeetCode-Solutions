class Solution:
    def removeOuterParentheses(self, S: str) -> str:
        cnt = 0
        lst = []
        lo = 0
        for i, ch in enumerate(S):
            if ch == '(':
                cnt += 1
            else:
                cnt -= 1
                if cnt == 0:
                    lst.append(S[lo + 1:i])
                    lo = i + 1
        return ''.join(lst)
