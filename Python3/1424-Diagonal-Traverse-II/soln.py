class Solution:
    def findDiagonalOrder(self, nums: List[List[int]]) -> List[int]:
        diags = collections.defaultdict(list)
        for i, row in enumerate(nums):
            for j, val in enumerate(row):
                diags[i + j].append(val)
        ans = []
        for _ in sorted(diags):
            ans.extend(diags[_][::-1])
        return ans
