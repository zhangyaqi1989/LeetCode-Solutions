class Solution:
    def findTheDifference(self, s: str, t: str) -> str:
        chars = [0] * 26
        for ch in s:
            chars[ord(ch) - 97] += 1
        for ch in t:
            if chars[ord(ch) - 97] == 0:
                return ch
            chars[ord(ch) - 97] -= 1
