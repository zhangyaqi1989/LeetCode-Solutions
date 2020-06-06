class Solution:
    def findWords(self, words):
        """
        :type words: List[str]
        :rtype: List[str]
        """
        # [qwertyuiop] [asdfghjkl] [zxcvbnm]
        d = {**dict(zip('qwertyuiop', itertools.repeat(1))), **dict(zip('asdfghjkl', itertools.repeat(2))), **dict(zip('zxcvbnm', itertools.repeat(3)))}
        ans = []
        for word in words:
            row = None
            for ch in word:
                ch = ch.lower()
                if row is None:
                    row = d[ch]
                else:
                    if row != d[ch]:
                        break
            else:
                ans.append(word)
        return ans