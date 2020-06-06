class Solution:
    def nextGreaterElement(self, n):
        """
        :type n: int
        :rtype: int
        """
        s = list(map(int, str(n)))
        i = len(s) - 1
        while i > 0 and s[i] <= s[i - 1]:
            i -= 1
        # 21
        if i == 0:
            return -1
        # S[i] > S[i - 1]
        j = i
        while j + 1 < len(s) and s[j + 1] > s[i - 1]:
            j += 1
        # find s[j + 1] <= s[i - 1]
        s[i-1], s[j] = s[j], s[i-1]
        s[i:] = reversed(s[i:])
        ans = int(''.join(map(str, s)))
        return ans if ans <= ((1<<31)-1) else -1