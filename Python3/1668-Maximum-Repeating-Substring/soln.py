class Solution:
    def maxRepeating(self, sequence: str, word: str) -> int:
        mx = len(sequence) // len(word)
        for repeat in range(1, mx + 2):
            sub = word * repeat
            if sub not in sequence:
                return repeat - 1
        return 0
