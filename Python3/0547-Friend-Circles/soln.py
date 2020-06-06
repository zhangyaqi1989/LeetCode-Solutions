class Solution:
    def findCircleNum(self, M):
        """
        :type M: List[List[int]]
        :rtype: int
        """
        cnt = 0
        seen = set()
        def dfs(start):
            stack = [start]
            seen.add(start)
            while stack:
                node = stack.pop()
                for nei, val in enumerate(M[node]):
                    if val and nei not in seen:
                        seen.add(nei)
                        stack.append(nei)
        for i in range(len(M)):
            if i not in seen:
                dfs(i)
                cnt += 1
        return cnt