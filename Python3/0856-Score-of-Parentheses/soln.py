class Solution:
    def scoreOfParentheses(self, S):
        """
        :type S: str
        :rtype: int
        """
        res = layers = 0
        for i in range(len(S) - 1):
            a, b = S[i], S[i + 1]
            layers += 1 if a == '(' else -1
            if a + b == '()': res += 2 ** (layers - 1)
        return res