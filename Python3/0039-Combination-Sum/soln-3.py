class Solution:
    def combinationSum(self, candidates, target):
        """
        :type candidates: List[int]
        :type target: int
        :rtype: List[List[int]]
        """
        ans = []
        candidates.sort()
        self.helper(candidates, 0, [], ans, target)
        return ans
        
    def helper(self, candidates, idx, cand, ans, target):
        if target == 0:
            ans.append(cand[:])
        elif target < candidates[idx]:
            return
        else:
            for i in range(idx, len(candidates)):
                cand.append(candidates[i])
                self.helper(candidates, i, cand, ans, target - candidates[i])
                cand.pop()