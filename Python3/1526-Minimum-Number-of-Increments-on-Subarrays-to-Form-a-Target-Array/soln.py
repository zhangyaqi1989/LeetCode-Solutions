class Solution:
    def minNumberOperations(self, target: List[int]) -> int:
        ans = target[0]
        n = len(target)
        pre = target[0]
        for i in range(1, n):
            ans += max(0, target[i] - pre)
            pre = target[i]
        return ans
