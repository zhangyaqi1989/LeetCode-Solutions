ass Solution:
    def numRabbits(self, answers):
        """
        :type answers: List[int]
        :rtype: int
        """
        # if (x + 1) has same color
        # (x + 1) will answer x
        # if n rabits answer x,...
        counts = collections.Counter(answers)
        return sum(math.ceil(counts[x] / (x + 1)) * (x + 1)
                   for x in counts)
