class Solution:
    def solveNQueens(self, n):
        """
        :type n: int
        :rtype: List[List[str]]
        """
        def encode(Q):
            n = len(Q)
            return ['.' * idx + 'Q' + '.' * (n - idx - 1) for idx in Q]
        
        def queen(Q, idx, solns):
            n = len(Q)
            if idx == n:
                solns.append(encode(Q))
            else:
                for i in range(n):
                    for j in range(idx):
                        if Q[j] == i or idx + i == j + Q[j] or idx - i == j - Q[j]:
                            break
                    else:
                        Q[idx] = i
                        queen(Q, idx + 1, solns)
        solns = []
        Q = [0] * n
        queen(Q, 0, solns)
        return solns
            
