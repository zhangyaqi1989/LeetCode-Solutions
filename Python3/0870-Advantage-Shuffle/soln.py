class Solution:
    def advantageCount(self, A, B):
        """
        :type A: List[int]
        :type B: List[int]
        :rtype: List[int]
        """
        # greedy
        A = sorted(A)
        B = sorted(zip(B, range(len(B))))
        ans = [0] * len(A)
        lo, hi = 0, len(A) - 1
        i = 0
        for num, _ in B:
            while i < len(A) and A[i] <= num:
                ans[B[hi][1]] = A[i]
                hi -= 1
                i += 1
            if i < len(A):
                ans[B[lo][1]] = A[i]
                lo += 1
                i += 1
            else:
                break
        return ans
