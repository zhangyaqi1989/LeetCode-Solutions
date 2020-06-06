class Solution:
    def findLongestChain(self, pairs: List[List[int]]) -> int:
        pairs = sorted(pairs, key=operator.itemgetter(1, 0))
        low = -math.inf
        cnt = 0
        for start, end in pairs:
            if start > low:
                low = end
                cnt += 1
        return cnt
