class Solution:
    def boldWords(self, words, S):
        """
        :type words: List[str]
        :type S: str
        :rtype: str
        """
        m = len(S)
        flags = [False] * m
        for word in words:
            n = len(word)
            for i in range(m - n + 1):
                if S[i:i + n] == word:
                    flags[i:i + n] = [True] * n
        ans = []
        for i, (flag, ch) in enumerate(zip(flags, S)):
            if flag:
                if i == 0 or not flags[i - 1]:
                    ans.append('<b>')
                ans.append(ch)
                if i == m - 1 or not flags[i + 1]:
                    ans.append('</b>')
            else:
                ans.append(ch)
        return ''.join(ans)