class Solution:
    def reversePairs(self, nums: List[int]) -> int:
        def count_and_sort(nums):
            if len(nums) <= 1:
                return 0, nums
            mid = len(nums) // 2
            left_cnt, left = count_and_sort(nums[:mid])
            right_cnt, right = count_and_sort(nums[mid:])
            cnt = left_cnt + right_cnt
            j = 0
            for i in range(len(left)):
                while j < len(right) and right[j] * 2 < left[i]:
                    j += 1
                cnt += j
            sorted_nums = list(heapq.merge(left, right))
            return cnt, sorted_nums
        return count_and_sort(nums)[0]
