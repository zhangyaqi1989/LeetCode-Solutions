class Solution:
    def repeatedNTimes(self, A):
        """
        :type A: List[int]
        :rtype: int
        """
        while True:
            a, b = random.sample(A, 2)
            if a == b:
                return a
