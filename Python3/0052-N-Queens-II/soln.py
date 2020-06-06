class Solution:
    def totalNQueens(self, n):
        """
        :type n: int
        :rtype: int
        """
        cnt = 0
        def queen(Q, idx):
            n = len(Q)
            nonlocal cnt
            if idx == n:
                cnt += 1
            else:
                for i in range(n):
                    for j in range(idx):
                        if Q[j] == i or idx + i == j + Q[j] or idx - i == j - Q[j]:
                            break
                    else:
                        Q[idx] = i
                        queen(Q, idx + 1)
        Q = [0] * n
        queen(Q, 0)
        return cnt
