class Solution:
    def reorderedPowerOf2(self, N):
        """
        :type N: int
        :rtype: bool
        """
        counter = collections.Counter(str(N))
        return any(counter == collections.Counter(str(1 << i))for i in range(32))
