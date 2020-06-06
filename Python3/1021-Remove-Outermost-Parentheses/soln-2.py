class Solution:
    def removeOuterParentheses(self, S: str) -> str:
        lst = []
        left = 1
        cnt = 0
        for i, ch in enumerate(S):
            if ch == '(':
                cnt += 1
            else:
                cnt -= 1
                if not cnt:
                    lst.append(S[left:i])
                    left = i + 2
        return ''.join(lst)
