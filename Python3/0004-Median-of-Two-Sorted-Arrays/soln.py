class Solution:
    def findMedianSortedArrays(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: float
        """
        l = len(nums1) + len(nums2)
        if l % 2:
            return self.helper(nums1, nums2, l // 2)
        else:
            return (self.helper(nums1, nums2, l // 2) + self.helper(nums1, nums2, (l - 1) // 2)) / 2
    def helper(self, a, b, k):
        if not a or not b:
            return (a or b)[k]
        ia, ib = len(a) // 2, len(b) // 2
        ma, mb = a[ia], b[ib]
        if k > ia + ib:
            if ma > mb:
                return self.helper(a, b[ib + 1:], k - ib - 1)
            else:
                return self.helper(a[ia + 1:], b, k - ia - 1)
        else: # k <= ia + ib
            if ma < mb:
                return self.helper(a, b[:ib], k)
            else:
                return self.helper(a[:ia], b, k)