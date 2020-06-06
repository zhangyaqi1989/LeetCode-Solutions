class Solution:
    def minKBitFlips(self, A: 'List[int]', K: 'int') -> 'int':
        n = len(A)
        cnt = 0
        cur = 0
        for i in range(n):
            if i >= K:
                cur -= A[i - K] // 2
            if (cur & 1) ^ A[i] == 0:
                if i + K > n:
                    return -1
                cnt += 1
                cur += 1
                A[i] += 2
        return cnt
