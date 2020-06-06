class Solution:
    def kthSmallestPrimeFraction(self, A: List[int], K: int) -> List[int]:
        lo, hi = 0, 1
        n = len(A)
        while True:
            mid = (lo + hi) / 2
            idxes = [bisect.bisect(A, num / mid) for num in A]
            cnt = sum(n - idx for idx in idxes)
            if cnt < K:
                lo = mid
            elif cnt > K:
                hi = mid
            else:
                return max([(A[i], A[idx]) for i, idx in enumerate(idxes) if idx < n], key=lambda x : (x[0] / x[1]))
