class Solution:
    def backspaceCompare(self, S, T):
        """
        :type S: str
        :type T: str
        :rtype: bool
        """
        i, j = len(S) - 1, len(T) - 1
        bs, bt = 0, 0
        while True:
            while i >= 0 and (bs or S[i] == '#'):
                bs = bs + 1 if S[i] == '#' else bs - 1
                i -= 1
            while j >= 0 and (bt or T[j] == '#'):
                bt = bt + 1 if T[j] == '#' else bt - 1
                j -= 1
            if not(i >= 0 and j >= 0 and S[i] == T[j]):
                return i == j == -1
            i, j = i - 1, j - 1