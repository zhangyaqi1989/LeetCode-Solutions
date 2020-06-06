class Solution:
    def judgeCircle(self, moves):
        """
        :type moves: str
        :rtype: bool
        """
        counter = collections.Counter(moves)
        return counter['L'] == counter['R'] and counter['U'] == counter['D']