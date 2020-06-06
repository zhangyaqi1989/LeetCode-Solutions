class Solution:
    def longestStrChain(self, words: List[str]) -> int:
        def valid(i, j):
            if len(words[i]) + 1 != len(words[j]):
                return False
            w1, w2 = words[i], words[j]
            for i, (a, b) in enumerate(zip(w1, w2)):
                if a != b:
                    return w1[i:] == w2[i + 1:]
            return True
        n = len(words)
        graph = [[] for _ in range(n)]
        groups = [[] for i in range(18)]
        for i, word in enumerate(words):
            groups[len(word)].append(i)
        for length in range(1, 16):
            for i in groups[length]:
                for j in groups[length + 1]:
                    if valid(i, j):
                        graph[i].append(j)
        paths = [0] * n
        def dfs(node):
            if paths[node] != 0:
                return paths[node]
            res = 0
            for nei in graph[node]:
                res = max(res, dfs(nei))
            paths[node] = res + 1
            return res + 1
        for node in range(n):
            dfs(node)
        return max(paths)
