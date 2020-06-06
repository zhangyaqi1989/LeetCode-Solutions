class Solution(object):
    def validWordSquare(self, words):
        """
        :type words: List[str]
        :rtype: bool
        """
        n = len(words)
        for i in range(n):
            for j, ch in enumerate(words[i]):
                # compare with ith col
                if j >= n or i >= len(words[j]) or ch != words[j][i]:
                    return False
        return True