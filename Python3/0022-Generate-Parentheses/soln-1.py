class Solution:
    def generateParenthesis(self, n):
        """
        :type n: int
        :rtype: List[str]
        """
        res = []
        self.combo(n, n, '', res)
        return res
        
    def combo(self, lefts, rights, combo, res):
        if lefts == rights == 0:
            res.append(combo)
        else:
            if lefts > rights or lefts < 0 or rights < 0:
                return
            if lefts == rights:
                self.combo(lefts - 1, rights, combo + '(', res)
            else:
                self.combo(lefts - 1, rights, combo + '(', res)
                self.combo(lefts, rights - 1, combo + ')', res)