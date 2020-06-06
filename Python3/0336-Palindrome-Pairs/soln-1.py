class Solution:
    def palindromePairs(self, words: List[str]) -> List[List[int]]:
        d = {w : i for i, w in enumerate(words)}
        ans = []
        for i, w in enumerate(words):
            rw = w[::-1]
            if rw in d and d[rw] != i:
                ans.append([i, d[rw]])
            if w != '' and rw == w and '' in d:
                ans.append([i, d['']])
                ans.append([d[''], i])
            for k in range(1, len(w)):
                s1, s2 = w[:k], w[k:]
                if s1 == s1[::-1] and s2[::-1] in d:
                    ans.append([d[s2[::-1]], i])
                if s2 == s2[::-1] and s1[::-1] in d:
                    ans.append([i, d[s1[::-1]]])
        return ans
