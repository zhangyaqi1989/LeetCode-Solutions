class Solution:
    def sortArray(self, nums: List[int]) -> List[int]:
        def quick_sort(nums):
            if len(nums) <= 1:
                return nums
            pivot = random.choice(nums)
            left = [num for num in nums if num < pivot]
            mid = [num for num in nums if num == pivot]
            right = [num for num in nums if num > pivot]
            return quick_sort(left) + mid + quick_sort(right)
        return quick_sort(nums)
