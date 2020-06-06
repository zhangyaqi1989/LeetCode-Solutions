class Solution:
    def minDeletionSize(self, A):
        """
        :type A: List[str]
        :rtype: int
        """
        n = len(A)
        done = [False] * (n - 1)
        ndone = 0
        m = len(A[0])
        cnt = 0
        for i in range(m):
            delete = False
            for j in range(n - 1):
                if A[j][i] > A[j + 1][i] and not done[j]:
                    delete = True
                    break
            if delete:
                cnt += 1
            else:
                for j in range(n - 1):
                    if A[j][i] < A[j + 1][i] and not done[j]:
                        done[j] = True
                        ndone += 1
            if ndone == n - 1:
                break
        return cnt
