class Solution:
    def superPow(self, a, b):
        """
        :type a: int
        :type b: List[int]
        :rtype: int
        """
        b = int(''.join(map(str, b)))
        return pow(a, b, 1337)