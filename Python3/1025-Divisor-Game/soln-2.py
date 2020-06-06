class Solution:
    def divisorGame(self, N: int) -> bool:
        # 1 false
        # 2 true
        # 3 false
        # 4 true
        # 5 false
        return not (N % 2)
