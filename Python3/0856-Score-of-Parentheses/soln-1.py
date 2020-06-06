class Solution:
    def scoreOfParentheses(self, S):
        """
        :type S: str
        :rtype: int
        """
        cnt, layer = 0, 0
        for a, b in zip(S, S[1:]):
            layer += (1 if a == '(' else -1)
            if a + b == '()':
                cnt += 2 ** (layer - 1)
        return cnt