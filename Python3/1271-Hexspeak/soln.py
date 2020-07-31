class Solution:
    def toHexspeak(self, num: str) -> str:
        s = "{:0X}".format(int(num))
        s = s.replace('0', 'O')
        s = s.replace('1', 'I')
        chars = "ABCDEFIO"
        return s if all(ch in chars for ch in s) else "ERROR"
