class Solution:
    def kEmptySlots(self, flowers, k):
        """
        :type flowers: List[int]
        :type k: int
        :rtype: int
        """
        bloom = []
        for day, flower in enumerate(flowers, 1):
            idx = bisect.bisect(bloom, flower)
            for neighbor in bloom[idx-(idx > 0):idx + 1]:
                if abs(flower - neighbor) - 1 == k:
                    return day
            bloom.insert(idx, flower)
        return -1