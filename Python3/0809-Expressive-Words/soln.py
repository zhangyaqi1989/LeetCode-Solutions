from itertools import zip_longest, groupby
class Solution:
    def expressiveWords(self, S, words):
        """
        :type S: str
        :type words: List[str]
        :rtype: int
        """
        groups = [(ch, len(list(g))) for ch, g in groupby(S)]
        cnt = 0
        for word in words:
            i = 0
            for i, (ch, g) in enumerate(groupby(word)):
                l = len(list(g))
                if ch != groups[i][0] or l > groups[i][1] or (groups[i][1] < 3 and l < groups[i][1]):
                    break
            else:
                if i == len(groups) - 1:
                    cnt += 1
        return cnt