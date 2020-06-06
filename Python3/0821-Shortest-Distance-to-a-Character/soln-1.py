class Solution:
    def shortestToChar(self, S, C):
        """
        :type S: str
        :type C: str
        :rtype: List[int]
        """
        ans = [float('inf')]
        for ch in S:
            if ch == C:
                ans.append(0)
            else:
                ans.append(ans[-1] + 1)
        ans = ans[1:]
        right = float('inf')
        for i in reversed(range(len(S))):
            if S[i] == C:
                right = i
            else:
                ans[i] = min(ans[i], right - i)
        return ans