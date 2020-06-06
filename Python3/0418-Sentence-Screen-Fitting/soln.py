class Solution:
    def wordsTyping(self, sentence, rows, cols):
        """
        :type sentence: List[str]
        :type rows: int
        :type cols: int
        :rtype: int
        """
        s = ' ' + ' '.join(sentence)
        i, cnt, n = 1, 0, len(s)
        for _ in range(rows):
            i += cols
            if i > n - 1:
                cnt += i // n
                i = i % n
            while s[i] != ' ':
                i -= 1
            i += 1
        return cnt