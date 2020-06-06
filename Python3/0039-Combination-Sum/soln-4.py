class Solution:
    def combinationSum(self, candidates, target):
        """
        :type candidates: List[int]
        :type target: int
        :rtype: List[List[int]]
        """
        candidates = sorted(candidates, reverse=True)
        def dfs(path, idx, paths, remain):
            if remain < 0:
                return
            elif remain == 0:
                paths.append(path)
            else:
                for i in range(idx, len(candidates)):
                    dfs(path + [candidates[i]], i, paths, remain - candidates[i])
        paths = []
        dfs([], 0, paths, target)
        return paths