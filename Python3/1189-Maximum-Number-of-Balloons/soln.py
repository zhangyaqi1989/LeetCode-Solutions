class Solution:
    def maxNumberOfBalloons(self, text: str) -> int:
        balloon = [('a', 1), ('b', 1), ('l', 2), ('o', 2), ('n', 1)]
        return min(text.count(ch) // cnt for ch, cnt in balloon)
