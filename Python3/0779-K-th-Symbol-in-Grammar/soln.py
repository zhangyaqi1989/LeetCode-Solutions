class Solution:
    def kthGrammar(self, N, K):
        """
        :type N: int
        :type K: int
        :rtype: int
        """
        # 0
        # 01
        # 0110
        return format(K - 1, 'b').count('1') % 2
