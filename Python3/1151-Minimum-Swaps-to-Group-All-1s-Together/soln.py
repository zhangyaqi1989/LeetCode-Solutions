class Solution:
    def minSwaps(self, data: List[int]) -> int:
        # minimum number of swaps
        k = data.count(1)
        ones = 0
        best = k
        for i, val in enumerate(data):
            ones += (val == 1)
            if i >= k:
                ones -= (data[i - k] == 1)
            if i >= k - 1:
                best = min(best, k - ones)
        return best
