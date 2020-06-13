class Solution:
    def sumZero(self, n: int) -> List[int]:
        if n == 1:
            return [0]
        ans = list(range(n - 1))
        ans.append(-sum(ans))
        return ans
