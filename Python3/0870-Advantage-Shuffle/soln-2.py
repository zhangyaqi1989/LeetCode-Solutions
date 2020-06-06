class Solution:
    def advantageCount(self, A, B):
        """
        :type A: List[int]
        :type B: List[int]
        :rtype: List[int]
        """
        # greedy
        n = len(A)
        A = sorted(A)
        B = sorted(zip(B, range(len(B))))
        ans = [0] * n
        i, hi = 0, n - 1
        for lo, (num, _) in enumerate(B):
            while i < n and A[i] <= num:
                ans[B[hi][1]] = A[i]
                hi -= 1
                i += 1
            if i < n:
                ans[B[lo][1]] = A[i]
                i += 1
            else:
                break
        return ans
