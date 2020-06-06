class Solution(object):
    def topKFrequent(self, words, k):
        """
        :type words: List[str]
        :type k: int
        :rtype: List[str]
        """
        counter = collections.Counter(words)
        return [key for _, key in heapq.nsmallest(k, [(-cnt, key) for key, cnt in counter.items()])]