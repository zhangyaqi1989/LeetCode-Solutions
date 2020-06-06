class Solution:
    def maxArea(self, h: int, w: int, hs: List[int], vs: List[int]) -> int:
        hs.sort()
        vs.sort()
        A = max(h - hs[-1], hs[0])
        for i in range(1, len(hs)):
            A = max(A, hs[i] - hs[i - 1])
        B = max(w - vs[-1], vs[0])
        for i in range(1, len(vs)):
            B = max(B, vs[i] - vs[i - 1])
        # print(A, B)
        return A * B % 1000000007
