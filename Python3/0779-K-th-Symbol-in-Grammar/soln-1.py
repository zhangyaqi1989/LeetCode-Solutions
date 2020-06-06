class Solution:
    def kthGrammar(self, N: int, K: int) -> int:
        # replace 0 with 01, replace 1 with 10
        if N == 1:
            return 0
        else:
            if K % 2 == 0:
                seed = self.kthGrammar(N - 1,  K / 2)
            else:
                seed = self.kthGrammar(N - 1, (K + 1) / 2)
            if seed == 1:
                if K % 2 == 0:
                    return 0
                else:
                    return 1
            else:
                if K % 2 == 0:
                    return 1
                else:
                    return 0
