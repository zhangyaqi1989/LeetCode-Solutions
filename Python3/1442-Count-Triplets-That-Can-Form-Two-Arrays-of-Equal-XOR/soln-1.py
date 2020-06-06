class Solution:
    def countTriplets(self, arr: List[int]) -> int:
        cur = 0
        seen = collections.Counter()
        seen[0] = 1
        # 0 <= i < j <= k < n
        n = len(arr)
        ans = 0
        for j, num in enumerate(arr):
            # check every j
            cur ^= num
            temp = cur
            for k in range(j + 1, n):
                temp ^= arr[k]
                b = temp ^ cur
                need = cur ^ b
                ans += seen.get(need, 0)
            seen[cur] += 1
        return ans
