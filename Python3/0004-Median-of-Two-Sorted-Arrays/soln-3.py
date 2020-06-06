class Solution:
    def findMedianSortedArrays(self, A: List[int], B: List[int]) -> float:
        def helper(loa, hia, lob, hib, k):
            # print(loa, hia, lob, hib)
            if loa >= hia or lob >= hib:
                if loa >= hia:
                    return B[lob + k]
                else:
                    return A[loa + k]
            else:
                la = hia - loa
                lb = hib - lob
                ia, ib = la // 2, lb // 2
                ma, mb = A[loa + ia], B[lob + ib]
                if k > ia + ib:
                    if ma > mb:
                        return helper(loa, hia, lob + ib + 1, hib, k - ib - 1)
                    else:
                        return helper(loa + ia + 1, hia, lob, hib, k - ia - 1)
                else:
                    # k <= ia + ib
                    if ma > mb:
                        return helper(loa, loa + ia, lob, hib, k)
                    else:
                        return helper(loa, hia, lob, lob + ib, k)
        n = len(A) + len(B)
        return helper(0, len(A), 0, len(B), n // 2) if n % 2 == 1 else 0.5 * (helper(0, len(A), 0, len(B), n // 2) + helper(0, len(A), 0, len(B), n // 2 - 1))
