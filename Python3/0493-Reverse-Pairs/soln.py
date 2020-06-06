class Solution:
    def reversePairs(self, nums: List[int]) -> int:
        def count_and_sort(lo, hi):
            if lo >= hi:
                return 0
            mid = (lo + hi) >> 1
            cnt = count_and_sort(lo, mid) + count_and_sort(mid + 1, hi)
            j = mid + 1
            for i in range(lo, mid + 1):
                while j <= hi and nums[i] > 2 * nums[j]:
                    j += 1
                cnt += j - (mid + 1)
            nums[lo:hi + 1] = sorted(nums[lo:hi + 1])
            return cnt
        return count_and_sort(0, len(nums) - 1)
