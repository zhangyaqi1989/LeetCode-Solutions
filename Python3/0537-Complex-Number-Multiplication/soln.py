class Solution:
    def complexNumberMultiply(self, a, b):
        """
        :type a: str
        :type b: str
        :rtype: str
        """
        def parse(string):
            real, img = string.split('+')
            return int(real), int(img.rstrip(' i'))
        r1, i1 = parse(a)
        r2, i2 = parse(b)
        return "{}+{}i".format(r1 * r2 - i1 * i2, r1 * i2 + r2 * i1)