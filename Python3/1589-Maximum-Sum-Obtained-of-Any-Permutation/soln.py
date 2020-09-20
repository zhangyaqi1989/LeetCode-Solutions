class Solution:
    def maxSumRangeQuery(self, nums: List[int], requests: List[List[int]]) -> int:
        # [1, 3], [0, 1]
        n = len(nums)
        changes = [0] * (n + 1)
        for start, end in requests:
            changes[start] += 1
            changes[end + 1] -= 1
        counter = [0] * n
        cnt = 0
        for i in range(n):
            cnt += changes[i]
            counter[i] = cnt
        ans = 0
        MOD = 1000000007
        for cnt, num in zip(sorted(counter, reverse=True), sorted(nums, reverse=True)):
            if cnt == 0:
                break
            ans = (ans + cnt * num) % MOD
        return ans
