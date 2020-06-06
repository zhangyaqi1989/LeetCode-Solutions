class Solution:
    def maximumSwap(self, num):
        """
        :type num: int
        :rtype: int
        """
        # check if there are larger digit after the cur digit
        digits = list(map(int, str(num)))
        d = dict(zip(digits, range(len(digits))))
        for i, digit in enumerate(digits):
            for val in range(9, digit, -1):
                if d.get(val, -1) > i:
                    digits[i], digits[d[val]] = digits[d[val]], digits[i]
                    return int(''.join(map(str, digits)))
        return num