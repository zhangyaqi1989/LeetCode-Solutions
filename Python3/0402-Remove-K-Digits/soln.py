class Solution:
    def removeKdigits(self, num, k):
        """
        :type num: str
        :type k: int
        :rtype: str
        """
        # this is a greedy algorithm
        out = []
        for d in num:
            while k and out and d < out[-1]:
                out.pop()
                k -= 1
            out.append(d)  
        # if k != 0, we need to use out[:-k]
        return ''.join(out[:-k or None]).lstrip('0') or '0'