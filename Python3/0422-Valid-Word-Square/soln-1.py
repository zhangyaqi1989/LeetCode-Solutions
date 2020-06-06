class Solution:
    def validWordSquare(self, words):
        """
        :type words: List[str]
        :rtype: bool
        """
        t = list(itertools.zip_longest(*words))
        return t == list(itertools.zip_longest(*t))