class Solution:
    def findMedianSortedArrays(self, A: List[int], B: List[int]) -> float:
        def helper(A, B, k):
            if not A or not B:
                return (A or B)[k]
            else:
                ia, ib = len(A) // 2, len(B) // 2
                ma, mb = A[ia], B[ib]
                if k > ia + ib:
                    if ma > mb:
                        return helper(A, B[ib + 1:], k - ib - 1)
                    else:
                        return helper(A[ia + 1:], B, k - ia - 1)
                else:
                    # k <= ia + ib
                    if ma > mb:
                        return helper(A[:ia], B, k)
                    else:
                        return helper(A, B[:ib], k)
        n = len(A) + len(B)
        return helper(A, B, n // 2) if n % 2 == 1 else 0.5 * (helper(A, B, n // 2) + helper(A, B, n // 2 - 1))
