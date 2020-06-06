from functools import lru_cache
import operator
class Solution:
    def diffWaysToCompute(self, expr: str) -> List[int]:
        funcs = {'+' : operator.add, '-' : operator.sub, '*' : operator.mul}
        @lru_cache(None)
        def helper(lo, hi):
            if expr[lo:hi].isdigit():
                return [int(expr[lo:hi])]
            return [func(l, r) for idx in range(lo, hi) if expr[idx] in '+-*'
                     for func in [funcs[expr[idx]]]
                     for l in helper(lo, idx)
                     for r in helper(idx + 1, hi)]
        return helper(0, len(expr))
