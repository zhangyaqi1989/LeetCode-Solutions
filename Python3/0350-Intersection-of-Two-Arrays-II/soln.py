import functools
class Solution(object):
    def intersect(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: List[int]
        """
        counter1, counter2 = collections.Counter(nums1), collections.Counter(nums2)
        if not counter1 & counter2:
            return []
        return functools.reduce(operator.add, ([key] * min(counter1[key], counter2[key]) for key in counter1 & counter2))