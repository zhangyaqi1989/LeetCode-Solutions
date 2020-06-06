class Solution:
    def permuteUnique(self, nums: List[int]) -> List[List[int]]:
        ans = [[]]
        for num in nums:
            ans = [item[:i] + [num] + item[i:] for item in ans for i in range((item + [num]).index(num) + 1)]
        return ans
