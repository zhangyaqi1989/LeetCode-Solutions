class Solution:
    def minimumIncompatibility(self, nums: List[int], k: int) -> int:
        counter = collections.Counter(nums)
        if counter.most_common(1)[0][1] > k:
            return -1
        sz = len(nums) // k
        @lru_cache(None)
        def dp(nums):
            if len(nums) == sz:
                return (max(nums) - min(nums)) if len(nums) == len(set(nums)) else math.inf
            pool = set(nums)
            ans = math.inf
            for cand in itertools.combinations(pool, sz):
                nums_lst = list(nums)
                for num in cand:
                    nums_lst.remove(num)
                ans = min(ans, dp(tuple(nums_lst)) + max(cand) - min(cand))
            return ans
        return dp(tuple(nums))
