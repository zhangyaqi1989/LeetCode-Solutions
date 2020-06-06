class Solution(object):
    def validWordAbbreviation(self, word, abbr):
        """
        :type word: str
        :type abbr: str
        :rtype: bool
        """
        i, j = 0, 0
        n = len(abbr)
        while i < n:
            if abbr[i] == '0':
                return False
            if abbr[i].isalpha():
                if j >= len(word) or abbr[i] != word[j]:
                    return False
                i += 1
                j += 1
            else:
                l = i
                while i < n and abbr[i].isdigit():
                    i += 1
                num = int(abbr[l:i])
                j += num
        return j == len(word)