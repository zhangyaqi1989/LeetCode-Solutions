class Solution:
    def minFlipsMonoIncr(self, S):
        """
        :type S: str
        :rtype: int
        """
        zero_counts, one_counts = {0 : 0}, {0 : 0}
        zeros, ones = 0, 0
        for i, ch in enumerate(S, 1):
            zeros += ch == '0'
            ones += ch == '1'
            zero_counts[i] = zeros
            one_counts[i] = ones
        one_counts = {idx : ones - cnt for idx, cnt in one_counts.items()}
        n = len(S)
        ans = n
        for i in range(n + 1):
            change = i - zero_counts[i] + (n - i) - one_counts[i]
            if change < ans:
                ans = change
        return ans