class Solution:
    def closeStrings(self, word1: str, word2: str) -> bool:
        def convert(s):
            counter = collections.Counter(s)
            return [counter[ch] for ch in s]
        w1 = convert(word1)
        w2 = convert(word2)
        return sorted(w1) == sorted(w2) and set(word1) == set(word2)
