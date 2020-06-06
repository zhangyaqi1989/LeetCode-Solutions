class Solution:
    def maxChunksToSorted(self, arr: List[int]) -> int:
        n = len(arr)
        left = [0] * n
        right = [0] * n
        left[0] = arr[0]
        for i in range(1, n):
            left[i] = max(arr[i], left[i - 1])
        right[n - 1] = arr[n - 1]
        for j in range(n - 2, -1, -1):
            right[j] = min(arr[j], right[j + 1])
        res = 1
        for i in range(n - 1):
            if left[i] <= right[i + 1]:
                res += 1
        return res
