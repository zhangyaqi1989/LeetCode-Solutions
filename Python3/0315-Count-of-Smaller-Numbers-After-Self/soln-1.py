class Solution:
    def countSmaller(self, nums: List[int]) -> List[int]:
        smallers = [0] * len(nums)
        def count_and_sort(nums):
            n = len(nums)
            if n <= 1:
                return nums
            half = n // 2
            left, right = count_and_sort(nums[:half]), count_and_sort(nums[half:])
            ans = [None] * n
            for i in reversed(range(n)):
                if not right or (left and left[-1][1] > right[-1][-1]):
                    smallers[left[-1][0]] += len(right)
                    ans[i] = left.pop()
                else:
                    ans[i] = right.pop()
            return ans
        count_and_sort(list(enumerate(nums)))
        return smallers
