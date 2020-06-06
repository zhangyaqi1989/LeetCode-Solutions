class Solution:
    def fourSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[List[int]]
        """
        if len(nums) < 4:
            return []
        # record sum of all pairs
        sums = collections.defaultdict(list)
        for i in range(len(nums) - 1):
            for j in range(i + 1, len(nums)):
                sums[nums[i] + nums[j]].append((i, j))
        keys = sorted(list(sums.keys()))
        l, r = 0, len(keys) - 1
        res = set()
        while l <= r: # only has one ...
            if keys[l] + keys[r] == target:
                for (i, j), (p, q) in itertools.product(sums[keys[l]], sums[keys[r]]):
                    if len(set((i, j, p, q))) == 4:
                        res.add(tuple(sorted((nums[i], nums[j], nums[p], nums[q]))))
                l, r = l + 1, r - 1
            elif keys[l] + keys[r] > target:
                r -= 1
            else:
                l += 1
        return list(res)