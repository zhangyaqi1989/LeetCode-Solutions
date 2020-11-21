class Solution:
    def closeStrings(self, word1: str, word2: str) -> bool:
        def convert(s):
            counter = collections.Counter(s)
            return collections.Counter(counter.values())
        cnt1 = convert(word1)
        cnt2 = convert(word2)
        return cnt1 == cnt2 and set(word1) == set(word2)
