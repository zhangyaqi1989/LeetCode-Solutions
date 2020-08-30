class Solution:
    def getMaxLen(self, nums: List[int]) -> int:
        seen = [-1, len(nums)]
        ans = 0
        cnt = 0
        for i, num in enumerate(nums):
            if num == 0:
                cnt = 0
                seen = [i, len(nums)]
            else:
                cnt = (cnt + (num < 0)) % 2
                if seen[cnt] != len(nums):
                    ans = max(ans, i - seen[cnt])
                else:
                    seen[cnt] = i
        return ans
