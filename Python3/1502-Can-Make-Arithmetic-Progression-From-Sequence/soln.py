class Solution:
    def canMakeArithmeticProgression(self, arr: List[int]) -> bool:
        arr.sort()
        n = len(arr)
        return len(set([arr[i + 1] - arr[i] for i in range(n - 1)])) == 1
