from functools import reduce
import operator
class Solution:
    def xorOperation(self, n: int, start: int) -> int:
        return reduce(operator.xor, (start + 2 * i for i in range(n)), 0)
