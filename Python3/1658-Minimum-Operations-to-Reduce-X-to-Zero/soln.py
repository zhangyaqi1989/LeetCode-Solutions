class Solution:
    def minOperations(self, nums: List[int], x: int) -> int:
        prefix = {0 : 0}
        acc = 0
        for i, num in enumerate(nums, 1):
            acc += num
            prefix[acc] = i
        ans = prefix.get(x, math.inf)
        sufix = 0
        for i in reversed(range(len(nums))):
            sufix += nums[i]
            if sufix > x:
                break
            else:
                need = x - sufix
                if (left_used := prefix.get(need, None)) is not None:
                    ans = min(ans, len(nums) - i + left_used)
        return ans if ans <= len(nums) else -1
