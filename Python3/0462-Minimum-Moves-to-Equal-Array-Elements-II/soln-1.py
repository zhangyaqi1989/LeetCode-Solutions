import statistics
class Solution:
    def minMoves2(self, nums: List[int]) -> int:
        mean = statistics.median(nums)
        return int(sum(abs(num - mean) for num in nums))
