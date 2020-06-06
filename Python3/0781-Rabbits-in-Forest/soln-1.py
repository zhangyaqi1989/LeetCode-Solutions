class Solution:
    def numRabbits(self, answers):
        """
        :type answers: List[int]
        :rtype: int
        """
        counts = collections.Counter(answers)
        return sum((counts[x] + x) // (x + 1) * (x + 1)
                   for x in counts)
