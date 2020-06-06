class Solution:
    def shiftingLetters(self, S, shifts):
        """
        :type S: str
        :type shifts: List[int]
        :rtype: str
        """
        s = sum(shifts)
        lst = list(S)
        for i, shift in enumerate(shifts):
            ch = ord(lst[i]) - 97
            ch = (ch + s) % 26
            lst[i] = chr(ch + 97)
            s -= shift
        return ''.join(lst)
