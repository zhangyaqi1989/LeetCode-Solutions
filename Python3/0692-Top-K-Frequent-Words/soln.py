class Solution:
    def topKFrequent(self, words, k):
        """
        :type words: List[str]
        :type k: int
        :rtype: List[str]
        """
        pairs = [(-cnt, word) for word, cnt in collections.Counter(words).items()]
        return [word for _, word in heapq.nsmallest(k, pairs)]