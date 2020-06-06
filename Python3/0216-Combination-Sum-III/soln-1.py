class Solution:
    def combinationSum3(self, k: int, target: int) -> List[List[int]]:
        def dfs(n, k, num, target, combo, ans):
            if target < 0 or len(combo) > k:
                return
            if target == 0:
                if len(combo) == k:
                    ans.append(combo[:])
            else:
                for nxt in range(num, n + 1):
                    combo.append(nxt)
                    dfs(n, k, nxt + 1, target - nxt, combo, ans)
                    combo.pop()
        ans = []
        dfs(9, k, 1, target, [], ans)
        return ans
