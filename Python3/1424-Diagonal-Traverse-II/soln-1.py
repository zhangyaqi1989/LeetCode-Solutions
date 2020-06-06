class Solution:
    def findDiagonalOrder(self, nums: List[List[int]]) -> List[int]:
        m, n = len(nums), max(len(row) for row in nums)
        diags = [[] for _ in range(m - 1 + n)]
        for i, row in enumerate(nums):
            for j, val in enumerate(row):
                diags[i + j].append(val)
        ans = []
        for lst in diags:
            ans.extend(lst[::-1])
        return ans
