class Solution:
    def findAllConcatenatedWordsInADict(self, words):
        """
        :type words: List[str]
        :rtype: List[str]
        """
        words = set(words)
        def dfs(word):
            if not word:
                return False
            n = len(word)
            stack = [0]
            seen = {0}
            while stack:
                node = stack.pop()
                if node == n:
                    return True
                for nei in range(node + 1, n + 1):
                    if word[node:nei] in words and nei not in seen and (node > 0 or nei < n):
                        stack.append(nei)
                        seen.add(nei)
            return False
        return [word for word in words if dfs(word)]
