class Solution:
    def findMedianSortedArrays(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: float
        """
        def helper(A, B, k):
            if not A or not B:
                return (A or B)[k]
            ia, ib = len(A) // 2, len(B) // 2
            ma, mb = A[ia], B[ib]
            if k > ia + ib:
                if ma > mb:
                    return helper(A, B[ib + 1:], k - ib - 1)
                else:
                    return helper(A[ia + 1:], B, k - ia - 1)
            else:
                if mb > ma:
                    return helper(A, B[:ib], k)
                else:
                    return helper(A[:ia], B, k)
        l = len(nums1) + len(nums2)
        if l & 1 == 1:
            return helper(nums1, nums2, l // 2)
        else:
            return 0.5 * (helper(nums1, nums2, l // 2) + helper(nums1, nums2, l // 2 - 1))