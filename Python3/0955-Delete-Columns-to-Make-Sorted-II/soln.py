class Solution(object):
    def minDeletionSize(self, A):
        """
        :type A: List[str]
        :rtype: int
        """
        done = [False] * (len(A) - 1)
        n = len(A)
        cnt = 0
        for t in zip(*A):
            for i in range(0, n - 1):
                if t[i] > t[i + 1] and not done[i]:
                    cnt += 1
                    break
            else:
                for i in range(0, n - 1):
                    if t[i] < t[i + 1] and not done[i]:
                        done[i] = True
        return cnt
