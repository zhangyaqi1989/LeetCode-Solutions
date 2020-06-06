class Solution:
    def areSentencesSimilarTwo(self, words1, words2, pairs):
        """
        :type words1: List[str]
        :type words2: List[str]
        :type pairs: List[List[str]]
        :rtype: bool
        """
        if len(words1) != len(words2): return False
        graph = collections.defaultdict(list)
        for a, b in pairs:
            graph[a].append(b)
            graph[b].append(a)
        def dfs(start, target):
            stack = [start]
            visited = {target}
            while stack:
                node = stack.pop()
                for nei in graph[node]:
                    if nei == target:
                        return True
                    if nei not in visited:
                        visited.add(nei)
                        stack.append(nei)
            return False
        return all(word1 == word2 or dfs(word1, word2) for word1, word2 in zip(words1, words2))