class Solution:
    def removeOuterParentheses(self, S: str) -> str:
        lst = []
        left = 0
        cnt = 0
        for i, ch in enumerate(S):
            if ch == '(':
                cnt += 1
            else:
                cnt -= 1
                if cnt == 0:
                    token = S[left:i + 1]
                    left = i + 1
                    lst.append(token[1:-1])
        return ''.join(lst)
