class Solution:
    def judgeCircle(self, moves):
        """
        :type moves: str
        :rtype: bool
        """
        if len(moves) & 1 == 1: return False
        counter = collections.Counter(moves)
        return counter['U'] == counter['D'] and counter['L'] == counter['R']