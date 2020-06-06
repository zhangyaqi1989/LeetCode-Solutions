class Solution:
    def palindromePairs(self, words):
        """
        :type words: List[str]
        :rtype: List[List[int]]
        """
        def isPalin(word):
            return word == word[::-1]
        words = {word : i for i, word in enumerate(words)}
        res = []
        for word, idx in words.items():
            n = len(word)
            for j in range(n + 1):
                pref = word[:j]
                suf = word[j:]
                if isPalin(pref) and suf[::-1] in words:
                    res.append([words[suf[::-1]], idx])
                if j != n and isPalin(suf) and pref[::-1] in words:
                    res.append([idx, words[pref[::-1]]])
        res = [[a, b] for a, b in res if a != b]
        return res