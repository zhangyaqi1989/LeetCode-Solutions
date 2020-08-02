class Solution:
    def maxSum(self, nums1: List[int], nums2: List[int]) -> int:
        cur1 = 0
        cur2 = 0
        res = 0
        N1, N2 = len(nums1), len(nums2)
        i, j = 0, 0
        while i < N1 and j < N2:
            if nums1[i] < nums2[j]:
                cur1 += nums1[i]
                i += 1
            elif nums1[i] > nums2[j]:
                cur2 += nums2[j]
                j += 1
            else:
                res += max(cur1, cur2) + nums1[i]
                cur1 = 0
                cur2 = 0
                i += 1
                j += 1
        while i < N1:
            cur1 += nums1[i]
            i += 1
        while j < N2:
            cur2 += nums2[j]
            j += 1
        return (res + max(cur1, cur2)) % 1000000007
