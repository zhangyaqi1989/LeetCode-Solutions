class Solution:
    def nextGreatestLetter(self, letters, target):
        """
        :type letters: List[str]
        :type target: str
        :rtype: str
        """
        lowercase = string.ascii_lowercase * 2
        idx = lowercase.find(target)
        cands = lowercase[idx + 1: idx + 27]
        return next(itertools.dropwhile(lambda ch : ch not in letters, cands))
