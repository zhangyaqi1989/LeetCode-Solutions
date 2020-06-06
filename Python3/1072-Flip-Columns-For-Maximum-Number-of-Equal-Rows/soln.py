class Solution:
    def maxEqualRowsAfterFlips(self, A: List[List[int]]) -> int:
        counter = collections.Counter()
        for row in A:
            counter[tuple(row)] += 1
            counter[tuple([1 - val for val in row])] += 1
        return max(counter.values())
