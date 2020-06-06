class Solution:
    def sortArray(self, nums: List[int]) -> List[int]:
        def mergesort(nums):
            n = len(nums)
            if n == 1:
                return nums
            half = n // 2
            left, right = mergesort(nums[:half]), mergesort(nums[half:])
            ans = [0] * n
            idx = n - 1
            while left or right:
                if not left:
                    ans[idx] = right.pop()
                elif not right:
                    ans[idx] = left.pop()
                else:
                    if right[-1] > left[-1]:
                        ans[idx] = right.pop()
                    else:
                        ans[idx] = left.pop()
                idx -= 1
            return ans
        return mergesort(nums)
