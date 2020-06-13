class Solution:
    def createTargetArray(self, nums: List[int], index: List[int]) -> List[int]:
        ans = []
        for num, idx in zip(nums, index):
            ans.insert(idx, num)
        return ans
