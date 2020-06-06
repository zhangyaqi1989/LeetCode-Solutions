class Solution:
    def canReorderDoubled(self, A):
        """
        :type A: List[int]
        :rtype: bool
        """
        # array of doubled pairs
        def valid(nums):
            if len(nums) % 2 == 1:
                return False
            counts = collections.Counter(nums)
            for num in sorted(nums):
                if counts[num]:
                    if counts[2 * num] == 0:
                        return False
                    else:
                        counts[2 * num] -= 1
                        counts[num] -= 1
            return True
        ps = [num for num in A if num >= 0]
        ns = [-num for num in A if num < 0]
        # print(ps, ns)
        return valid(ps) and valid(ns)
