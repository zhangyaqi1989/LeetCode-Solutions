class Solution:
    def loudAndRich(self, richer, quiet):
        """
        :type richer: List[List[int]]
        :type quiet: List[int]
        :rtype: List[int]
        """
        graph = collections.defaultdict(list)
        for x, y in richer:
            graph[y].append(x)
        # return the root of a component
        res = [-1] * len(quiet)
        def dfs(i):
            if res[i] != -1:
                return res[i]
            res[i] = i
            for nei in graph[i]:
                if quiet[res[i]] > quiet[dfs(nei)]:
                    res[i] = res[nei]
            return res[i]
        for i in range(len(quiet)):
            res[i] = dfs(i)
        return res
