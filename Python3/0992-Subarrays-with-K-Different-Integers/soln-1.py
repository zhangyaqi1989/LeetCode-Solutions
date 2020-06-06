class Solution:
    def subarraysWithKDistinct(self, A: List[int], K: int) -> int:
        # number fo subarrays with distinct integers more than or equal to K
        def helper(K):
            window = collections.Counter()
            lo = 0
            cnt = 0
            for i, num in enumerate(A):
                window[num] += 1
                while len(window) >= K:
                    window[A[lo]] -= 1
                    if window[A[lo]] == 0:
                        window.pop(A[lo])
                    lo += 1
                cnt += lo
            return cnt
        return helper(K) - helper(K + 1)
