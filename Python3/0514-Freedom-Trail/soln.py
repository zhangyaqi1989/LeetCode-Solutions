class Solution:
    def findRotateSteps(self, ring, key):
        """
        :type ring: str
        :type key: str
        :rtype: int
        """
        # at least there is one ch in key
        indexes = collections.defaultdict(list)
        dp = [0] * len(ring)
        pre = key[0]
        n = len(ring)
        for i, c in enumerate(ring):
            indexes[c].append(i)
        for i in indexes[key[0]]:
            dp[i] = min(i, n - i) + 1
        for c in key[1:]:
            for i in indexes[c]:
                dp[i] = min(dp[j] + min(i - j, j + n - i) if i >= j else dp[j] + min(j - i, i + n - j) for j in indexes[pre]) + 1
            pre = c
        return min(dp[i] for i in indexes[key[-1]])