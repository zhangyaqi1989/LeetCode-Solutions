class Solution:
    def generateParenthesis(self, n):
        """
        :type n: int
        :rtype: List[str]
        """
        res = []
        self.helper(n, n, '', res)
        return res
    
    def helper(self, left, right, combi, res):
        if left == right == 0:
            res.append(combi)
            return
        if left > right or left < 0 or right < 0:
            return
        self.helper(left - 1, right, combi + '(', res)
        self.helper(left, right - 1, combi + ')', res)