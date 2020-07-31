class Solution:
    def calculateTime(self, keyboard: str, word: str) -> int:
        positions = {key : i for i, key in enumerate(keyboard)}
        n = len(word)
        ans = 0
        for i in range(1, n):
            ans += abs(positions[word[i]] - positions[word[i - 1]])
        return ans + positions[word[0]]
