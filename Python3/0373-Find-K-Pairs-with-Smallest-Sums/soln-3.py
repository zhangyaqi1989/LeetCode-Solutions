class Solution:
    def kSmallestPairs(self, nums1: List[int], nums2: List[int], k: int) -> List[List[int]]:
        return [suv[1:] for suv in heapq.nsmallest(k, [(u + v, u, v) for u in nums1 for v in nums2])]
