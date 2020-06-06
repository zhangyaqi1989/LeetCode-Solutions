class Solution:
    def combinationSum(self, candidates, target):
        """
        :type candidates: List[int]
        :type target: int
        :rtype: List[List[int]]
        """
        # no duplicates
        res = []
        self.helper(candidates, target, [], res)
        return res
        
    def helper(self, cands, target, combi, res):
        if target == 0:
            res.append(combi)
            return
        if target < 0:
            return
        for cand in cands:
            if not combi or cand >= combi[-1]:
                self.helper(cands, target - cand, combi + [cand], res)