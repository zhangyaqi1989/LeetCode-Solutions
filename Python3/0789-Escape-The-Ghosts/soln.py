class Solution:
    def escapeGhosts(self, ghosts, target):
        """
        :type ghosts: List[List[int]]
        :type target: List[int]
        :rtype: bool
        """
        x, y = target
        dis = abs(x) + abs(y)
        return all(abs(a - x) + abs(b - y) > dis for a, b in ghosts)