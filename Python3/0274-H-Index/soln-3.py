class Solution:
    def hIndex(self, citations: List[int]) -> int:
        n = len(citations)
        buckets = [0] * (n + 1)
        for c in citations:
            if c >= n:
                buckets[n] += 1
            else:
                buckets[c] += 1
        count = 0
        for i in range(n, -1, -1):
            count += buckets[i]
            if count >= i:
                return i
        return 0
