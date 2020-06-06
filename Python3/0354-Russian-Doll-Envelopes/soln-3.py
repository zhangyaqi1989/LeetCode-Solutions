class Solution:
    def maxEnvelopes(self, envelopes: List[List[int]]) -> int:
        # this is LIS
        if not envelopes:
            return 0
        envelopes.sort(key=lambda x : (x[0], -x[1]))
        tails = []
        for e in envelopes:
            h = e[1]
            idx = bisect.bisect_left(tails, h)
            if idx >= len(tails):
                tails.append(h)
            else:
                tails[idx] = h
        return len(tails)
