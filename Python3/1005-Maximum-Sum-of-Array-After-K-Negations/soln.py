class Solution:
    def largestSumAfterKNegations(self, A: List[int], K: int) -> int:
        ans = sum(A)
        nums = heapq.nsmallest(K, A)
        for i, num in enumerate(nums):
            if K == 0 or num >= 0:
                break
            K -= 1
            ans -= 2 * num
            nums[i] = -nums[i]
        if K > 0 and K % 2 == 1:
            mn = min(nums)
            ans -= 2 * mn
        return ans
