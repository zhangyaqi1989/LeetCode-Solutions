class Solution:
    def longestDecomposition(self, text: str) -> int:
        n = len(text)
        if n <= 1:
            return n
        for i in range(n // 2):
            if text[:i + 1] == text[-(i + 1):]:
                return 2 + self.longestDecomposition(text[(i + 1):-(i + 1)])
        return 1
