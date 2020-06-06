class Solution:
    def crackSafe(self, n, k):
        """
        :type n: int
        :type k: int
        :rtype: str
        """
        ans = ['0'] * n
        visited = {'0' * n}
        total = k ** n
        self.dfs(ans, visited, total, n, k)
        return ''.join(ans)
    
    def dfs(self, ans, visited, total, n, k):
        if len(visited) == total:
            return True
        for i in map(str, range(k)):
            nxt = ''.join(ans[-(n - 1) or len(ans):]) + i
            if nxt not in visited:
                visited.add(nxt)
                ans += [i]
                if self.dfs(ans, visited, total, n, k):
                    return True
                else:
                    visited.remove(nxt)
                    ans.pop()
        return False