class Solution:
    def fourSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[List[int]]
        """
        d = collections.defaultdict(list)
        n = len(nums)
        for i in range(n):
            for j in range(i + 1, n):
                d[nums[i] + nums[j]].append((i, j))
        ans = set()
        for i in range(n):
            for j in range(i + 1, n):
                need = target - nums[i] - nums[j]
                if need in d:
                    for p, q in d[need]:
                        if len({i, j, p, q}) == 4:
                            cand = tuple(sorted([nums[i], nums[j], nums[p], nums[q]]))
                            if cand not in ans:
                                ans.add(cand)
        return list(map(list, ans))