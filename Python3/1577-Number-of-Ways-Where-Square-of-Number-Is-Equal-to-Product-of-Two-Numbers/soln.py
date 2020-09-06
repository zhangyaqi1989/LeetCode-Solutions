class Solution:
    def numTriplets(self, nums1: List[int], nums2: List[int]) -> int:
        c1 = collections.Counter(nums1)
        c2 = collections.Counter(nums2)
        l1 = sorted(c1)
        l2 = sorted(c2)
        def helper(l1, l2, c1, c2):
            ans = 0
            for v1 in l1:
                v1square = v1 * v1
                for v2 in l2:
                    if v1square % v2 == 0:
                        v3 = v1square // v2
                        if v3 < v2:
                            continue
                        idx = bisect.bisect_left(l2, v3)
                        if idx < len(l2) and l2[idx] == v3:
                            if v2 != v3:
                                ans += c1[v1] * c2[v2] * c2[v3]
                            else:
                                ans += c1[v1] * c2[v2] * (c2[v2] - 1) // 2
            return ans
        return helper(l1, l2, c1, c2) + helper(l2, l1, c2, c1)
