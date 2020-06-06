class Solution:
    def splitLoopedString(self, strs):
        """
        :type strs: List[str]
        :rtype: str
        """
        B = [max(x, x[::-1]) for x in strs]
        ans = ""
        for i, token in enumerate(B):
            for start in (token, token[::-1]):
                for j in range(len(start) + 1):
                    ans = max(ans, start[j:] + "".join(B[i+1:] + B[:i]) + start[:j])
        return ans