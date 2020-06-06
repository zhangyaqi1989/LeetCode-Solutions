class Solution:
    def generateParenthesis(self, n):
        """
        :type n: int
        :rtype: List[str]
        """
        n = n * 2
        def dfs(n, unbalanced, path, paths):
            if len(path) == n:
                if unbalanced == 0:
                    paths.append(path)
                return
            if unbalanced < 0:
                return
            dfs(n, unbalanced + 1 , path + '(', paths)
            dfs(n, unbalanced - 1 , path + ')', paths)
        paths = []
        dfs(n, 0, '', paths)
        return paths