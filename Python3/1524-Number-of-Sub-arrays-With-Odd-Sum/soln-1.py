class Solution:
    def numOfSubarrays(self, arr: List[int]) -> int:
        pres = [1, 0]
        cur = 0
        ans = 0
        for num in arr:
            cur = (cur + num) % 2
            ans += pres[1 - cur]
            pres[cur] += 1
        return ans % 1000000007
