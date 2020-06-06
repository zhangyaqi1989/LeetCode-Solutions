class Solution:
    def generatePossibleNextMoves(self, s):
        """
        :type s: str
        :rtype: List[str]
        """
        lst = []
        i = 0
        while i < len(s):
            i = s.find('++', i)
            if i != -1:
                lst.append(s[:i] + '--' + s[i + 2:])
                i += 1
            else:
                break
        return lst
