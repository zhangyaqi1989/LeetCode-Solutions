class Solution:
    def firstUniqChar(self, s: str) -> int:
        chars = [0] * 26
        for ch in s:
            chars[ord(ch) - 97] += 1
        for i, ch in enumerate(s):
            if chars[ord(ch) - 97] == 1:
                return i
        return -1
