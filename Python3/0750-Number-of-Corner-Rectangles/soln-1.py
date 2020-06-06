class Solution:
    def countCornerRectangles(self, grid: List[List[int]]) -> int:
        def toBin(lst):
            ans = 0
            for num in lst:
                ans = ans * 2 + num
            return ans
        nums = [toBin(row) for row in grid]
        cnt = 0
        for num1, num2 in itertools.combinations(nums, 2):
            ones = bin(num1 & num2).count('1')
            cnt += ones * (ones - 1) // 2
        return cnt
