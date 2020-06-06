class Solution:
    def generatePossibleNextMoves(self, s):
        """
        :type s: str
        :rtype: List[str]
        """
        return [s[:m.start()] + '--' + s[m.start() + 2:] for m in re.finditer('(?=(\+\+))', s)] # search anything followed by this pattern