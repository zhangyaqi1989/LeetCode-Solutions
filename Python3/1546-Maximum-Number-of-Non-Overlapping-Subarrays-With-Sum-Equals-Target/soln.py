class Solution:
    def maxNonOverlapping(self, nums: List[int], target: int) -> int:
        seen = {0}
        cur = 0
        cnt = 0
        for num in nums:
            cur += num
            if (cur - target) in seen:
                cnt += 1
                seen.clear()
            seen.add(cur)
        return cnt
