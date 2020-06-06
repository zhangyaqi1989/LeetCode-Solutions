class Solution:
    def checkIfCanBreak(self, s1: str, s2: str) -> bool:
        l1 = sorted(s1)
        l2 = sorted(s2)
        return all(c1 >= c2 for c1, c2 in zip(l1, l2)) or all(c2 >= c1 for c1, c2 in zip(l1, l2))
