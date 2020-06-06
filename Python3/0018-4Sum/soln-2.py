class Solution:
    def fourSum(self, nums: List[int], target: int) -> List[List[int]]:
        memo = collections.defaultdict(list)
        n = len(nums)
        for i in range(n):
            for j in range(i + 1, n):
                memo[nums[i] + nums[j]].append((i, j))
        ans = set()
        for i in range(n):
            for j in range(i + 1, n):
                need = target - nums[i] - nums[j]
                if need in memo:
                    for ii, jj in memo[need]:
                        if len(set([i, j, ii, jj])) == 4:
                            ans.add(tuple(sorted([nums[i], nums[j], nums[ii], nums[jj]])))
        return [list(item) for item in ans]
