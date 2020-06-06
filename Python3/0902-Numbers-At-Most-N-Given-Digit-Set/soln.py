class Solution:
    def atMostNGivenDigitSet(self, D, N):
        """
        :type D: List[str]
        :type N: int
        :rtype: int
        """
        str_N = str(N)
        n, m = len(str_N), len(D)
        D = set(D)
        # for i < N, it is just permutation
        cnt = sum(m ** i for i in range(1, n))
        i = 0
        while i < n:
            val = sum(digit < str_N[i] for digit in D) * (m ** (n - 1 - i))
            cnt += val
            if str_N[i] not in D:
                break
            i += 1
        return cnt if i != n else cnt + 1
