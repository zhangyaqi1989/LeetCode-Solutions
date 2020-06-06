class Solution:
    def mirrorReflection(self, p, q):
        """
        :type p: int
        :type q: int
        :rtype: int
        """
        g = math.gcd(p, q)
        p = (p // g) % 2
        q = (q // g) % 2
        return 1 if p and q else 0 if p else 2