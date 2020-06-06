class Solution:
    def maxSumOfThreeSubarrays(self, nums: List[int], k: int) -> List[int]:
        idx1, idx2, idx3 = 0, k, k * 2
        s1, s2, s3 = sum(nums[idx1:idx1 + k]), sum(nums[idx2:idx2 + k]), sum(nums[idx3:idx3 + k])
        bests1, bests12, bests123 = s1, s1 + s2, s1 + s2 + s3
        besti1 = 0
        besti12 = [idx1, idx2]
        besti123 = [idx1, idx2, idx3]
        idx1 += 1
        idx2 += 1
        idx3 += 1
        n = len(nums)
        while idx3 + k <= n:
            s1 += nums[idx1 + k - 1] - nums[idx1 - 1]
            s2 += nums[idx2 + k - 1] - nums[idx2 - 1]
            s3 += nums[idx3 + k - 1] - nums[idx3 - 1]
            if s1 > bests1:
                bests1 = s1
                besti1 = idx1
            if bests1 + s2 > bests12:
                bests12 = bests1 + s2
                besti12 = [besti1, idx2]
            if bests12 + s3 > bests123:
                bests123 = bests12 + s3
                besti123 = besti12 + [idx3]
            idx1 += 1
            idx2 += 1
            idx3 += 1
        return besti123
