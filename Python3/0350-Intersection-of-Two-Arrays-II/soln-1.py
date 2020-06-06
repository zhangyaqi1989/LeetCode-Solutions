class Solution:
    def intersect(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: List[int]
        """
        counter1, counter2 = collections.Counter(nums1), collections.Counter(nums2)
        return list(itertools.chain.from_iterable([num] * min(counter1[num], counter2[num]) for num in counter1 & counter2))