class Solution:
    def bagOfTokensScore(self, tokens, P):
        """
        :type tokens: List[int]
        :type P: int
        :rtype: int
        """
        tokens = sorted(tokens)
        i, j = 0, len(tokens) - 1
        cnt = 0
        while i <= j:
            if P >= tokens[i]:
                P -= tokens[i]
                cnt += 1
                i += 1
            else:
                if cnt > 0 and j > i and P + tokens[j] >= tokens[i]:
                    P = P + tokens[j] - tokens[i]
                    j -= 1
                    i += 1
                else:
                    break
        return cnt
