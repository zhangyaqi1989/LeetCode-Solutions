class Solution:
    def jump(self, nums: List[int]) -> int:
        cnt = 0
        end = 0
        farthest = 0
        for i, num in enumerate(nums):
            farthest = max(farthest, i + num)
            if end >= len(nums) - 1:
                break
            if i == end:
                cnt += 1
                end = farthest
        return cnt
