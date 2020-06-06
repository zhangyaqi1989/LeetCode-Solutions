class Solution:
    def findRotateSteps(self, ring: str, key: str) -> int:
        idxes = collections.defaultdict(list)
        for i, ch in enumerate(ring):
            idxes[ch].append(i)
        n = len(ring)
        dp = [0] * n
        for i in idxes[key[0]]:
            dp[i] = min(i, n - i) + 1
        pre = key[0]
        for i in range(1, len(key)):
            ch = key[i]
            for j in idxes[ch]:
                dp[j] = min(dp[k] + (min(j - k, k - j + n) if j >= k else min(k - j, j - k + n)) for k in idxes[pre]) + 1
            pre = ch
        return min(dp[i] for i in idxes[key[-1]])
