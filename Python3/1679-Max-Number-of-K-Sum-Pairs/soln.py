class Solution:
    def maxOperations(self, nums: List[int], k: int) -> int:
        counter = collections.Counter(nums)
        uniques = list(counter)
        ans = 0
        for num in sorted(uniques):
            if num < k // 2:
                ans += min(counter[num], counter[k - num])
            elif num == k // 2:
                if k % 2 == 0:
                    ans += counter[num] // 2
                else:
                    ans += min(counter[num], counter[k - num])
        return ans
