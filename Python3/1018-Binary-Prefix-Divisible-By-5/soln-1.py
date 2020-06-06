class Solution:
    def prefixesDivBy5(self, A: List[int]) -> List[bool]:
        n = len(A)
        ans = [False] * n
        val = 0
        for i, num in enumerate(A):
            val = (val * 2 + num) % 5
            if val == 0:
                ans[i] = True
        return ans
