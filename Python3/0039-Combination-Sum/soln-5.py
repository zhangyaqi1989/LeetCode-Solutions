class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        def dfs(target, idx, combo, ans):
            if target == 0:
                ans.append(combo[:])
            elif target > 0:
                for i in range(idx, len(candidates)):
                    combo.append(candidates[i])
                    dfs(target - candidates[i], i, combo, ans)
                    combo.pop()
        ans = []
        dfs(target, 0, [], ans)
        return ans
