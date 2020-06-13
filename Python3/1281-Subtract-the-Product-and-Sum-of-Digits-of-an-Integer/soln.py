class Solution:
    def subtractProductAndSum(self, n: int) -> int:
        digits = [int(d) for d in str(n)]
        return reduce(operator.mul, digits) - sum(digits)
