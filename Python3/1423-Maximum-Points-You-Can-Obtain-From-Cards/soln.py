class Solution:
    def maxScore(self, nums: List[int], k: int) -> int:
        pres = [0]
        for num in nums:
            pres.append(pres[-1] + num)
        sufs = [0]
        for num in reversed(nums):
            sufs.append(sufs[-1] + num)
        ans = -1
        for pick in range(k + 1):
            ans = max(ans, pres[pick] + sufs[k - pick])
        return ans
