class Solution:
    def checkArithmeticSubarrays(self, nums: List[int], l: List[int], r: List[int]) -> List[bool]:
        def is_seq_arithmetic(lo, hi):
            if lo == hi:
                return False
            vals = nums[lo:hi + 1]
            vals.sort()
            d = vals[1] - vals[0]
            return all(vals[i + 1] - vals[i] == d for i in range(len(vals) - 1))
        return [is_seq_arithmetic(lo, hi) for lo, hi in zip(l, r)]
