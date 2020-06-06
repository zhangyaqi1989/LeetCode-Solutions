class Solution:
    def hIndex(self, citations):
        """
        :type citations: List[int]
        :rtype: int
        """
        citations = [-c for c in citations]
        heapq.heapify(citations)
        h = 0
        while citations:
            h += 1
            c = abs(heapq.heappop(citations))
            if c < h:
                return h - 1
        return h
