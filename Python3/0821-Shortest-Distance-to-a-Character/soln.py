class Solution:
    def shortestToChar(self, S, C):
        """
        :type S: str
        :type C: str
        :rtype: List[int]
        """
        res = []
        for idx, ch in enumerate(S):
            if ch == C:
                res.append(0)
            else:
                if not res:
                    res.append(float('inf'))
                else:
                    res.append(res[-1] + 1)
        for j in range(len(S) - 1, -1, -1):
            if S[j] != C:
                right = right + 1 if j < len(S) - 1 else float('inf')
            else:
                right = 0
            res[j] = min(res[j], right)
        return res