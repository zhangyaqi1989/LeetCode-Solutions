from fractions import Fraction
from functools import reduce
class Solution:
    def fractionAddition(self, expression):
        """
        :type expression: str
        :rtype: str
        """
        def parse(fracture):
            "Parse a fraction."
            num, den = fracture.split('/')
            return Fraction(int(num), int(den))
        fs = list(map(parse, re.findall(r'[+-]?[\d]+/[\d]+', expression)))
        # print(fs)
        ans = reduce(operator.add, fs)
        return '{}/{}'.format(ans.numerator, ans.denominator)
