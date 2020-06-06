class Solution:
    def findBestValue(self, arr: List[int], target: int) -> int:
        if sum(arr) <= target:
            return max(arr)
        arr.sort()
        idx = 0
        n = len(arr)
        hi = max(arr)
        best_diff = math.inf
        best_val = 0
        left = 0
        for val in range(hi + 1):
            while idx < n and arr[idx] <= val:
                left += arr[idx]
                idx += 1
            diff = abs(left + (n - idx) * val - target)
            if diff < best_diff:
                best_diff = diff
                best_val = val
        return best_val
