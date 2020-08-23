class Solution:
    def threeConsecutiveOdds(self, arr: List[int]) -> bool:
        n = len(arr)
        return any(arr[i] % 2 + arr[i + 1] % 2 + arr[i + 2] % 2 == 3 for i in range(n - 2))
