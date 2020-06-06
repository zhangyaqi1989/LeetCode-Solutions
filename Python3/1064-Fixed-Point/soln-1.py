class Solution:
    def fixedPoint(self, A: List[int]) -> int:
        return next(itertools.dropwhile(lambda p : p[0] != p[1], enumerate(A)), [-1])[0]
