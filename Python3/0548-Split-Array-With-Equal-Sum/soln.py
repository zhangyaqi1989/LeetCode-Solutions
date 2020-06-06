class Solution:
    def splitArray(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        # (0, i - 1), (i + 1, j - 1), (j + 1, k - 1) and (k + 1, n - 1)
        # P[i] = P[j] - P[i+1] = P[k] - P[j+1] = P[-1] - P[k+1]
        P = [0]
        for x in nums: P.append(P[-1] + x)
        N = len(nums)
        d = collections.defaultdict(list)
        for i, u in enumerate(P):
            d[u].append(i)
        for j in range(1, N - 1):
            for k in range(j + 1, N - 1):
                for i in d[P[-1] - P[k + 1]]:
                    if i > j: break
                    if P[i] == P[j] - P[i + 1] == P[k] - P[j + 1]:
                        return True
        return False