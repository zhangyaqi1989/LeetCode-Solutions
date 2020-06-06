class Solution:
    def palindromePairs(self, words: List[str]) -> List[List[int]]:
        # abcd + dcba
        def valid(w):
            return w == w[::-1]
        words = {w : i for i, w in enumerate(words)}
        ans = []
        for w, i in words.items():
            n = len(w)
            for k in range(1, n + 1):
                prefix = w[:k]
                if valid(prefix):
                    add = w[k:][::-1]
                    if add in words:
                        ans.append([words[add], i])
                suffix = w[-k:]
                if valid(suffix):
                    add = w[:-k][::-1]
                    if add in words:
                        ans.append([i, words[add]])
            if w[::-1] != w and w[::-1] in words:
                ans.append([i, words[w[::-1]]])
        return ans
