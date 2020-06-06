class Solution:
    def findAndReplacePattern(self, words: List[str], pattern: str) -> List[str]:
        def normalize(word):
            m = {}
            return [m.setdefault(ch, len(m)) for ch in word]
        np = normalize(pattern)
        def valid(word):
            return normalize(word) == np
        return [word for word in words if valid(word)]
