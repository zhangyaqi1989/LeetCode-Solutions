class Solution:
    def fullJustify(self, words, maxWidth):
        """
        :type words: List[str]
        :type maxWidth: int
        :rtype: List[str]
        """
        res, row, nletters = [], [], 0
        for word in words:
            if nletters + len(word) + len(row) > maxWidth:
                for i in range(maxWidth - nletters):
                    row[i % (len(row) - 1 or 1)] += ' '
                res.append(''.join(row))
                row, nletters = [], 0
            row += [word]
            nletters += len(word)
        return res + [(' '.join(row)).ljust(maxWidth)]