# Naive
class Solution:
    def minWindow(self, S, T):
        """
        :type S: str
        :type T: str
        :rtype: str
        """
        # T is a subsequence of S
        # sliding window
        if len(T) > len(S):
            return ''
        ans, min_length = '', len(S)
        for i in range(len(S) - len(T) + 1):
            j = 0
            for k in range(i, len(S)):
                if S[k] == T[j]:
                    j += 1
                    if j == len(T):
                        cur_length = k - i + 1
                        if cur_length < min_length:
                            min_length = cur_length
                            ans = S[i:k + 1]
                        break
        return ans