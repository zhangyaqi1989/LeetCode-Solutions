class Solution:
    def findMaximumXOR(self, nums: List[int]) -> int:
        mx = 0
        for i in reversed(range(31)):
            prefixes = set(num >> i for num in nums)
            mx <<= 1
            cand = mx + 1
            for prefix in prefixes:
                if (cand ^ prefix) in prefixes:
                    mx = cand
                    break
        return mx
