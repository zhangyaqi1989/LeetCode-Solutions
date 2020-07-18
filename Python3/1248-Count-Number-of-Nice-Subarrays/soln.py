class Solution:
    def numberOfSubarrays(self, nums: List[int], k: int) -> int:
        # subarray
        seen = [0] * (len(nums) + 1)
        seen[0] = 1
        acc = 0
        ans = 0
        for num in nums:
            acc += num % 2
            ans += seen[acc - k]
            seen[acc] += 1
        return ans
