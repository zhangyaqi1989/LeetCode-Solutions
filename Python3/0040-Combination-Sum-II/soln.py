class Solution(object):
    def combinationSum2(self, candidates, target):
        """
        :type candidates: List[int]
        :type target: int
        :rtype: List[List[int]]
        """
        # each number may only use once
        # it can contains duplicates
        candidates.sort()
        res = []
        self.helper(candidates, 0, target, [], res)
        return res
    
    
    def helper(self, cands, idx, target, combi, res):
        if target == 0:
            res.append(combi)
            return
        if target < 0:
            return
        for i in range(idx, len(cands)):
            if i > idx and cands[i] == cands[i - 1]: continue
            self.helper(cands, i + 1, target - cands[i], combi + [cands[i]], res)