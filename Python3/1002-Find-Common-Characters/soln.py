class Solution:
    def commonChars(self, A: List[str]) -> List[str]:
        chars = [math.inf] * 26
        for string in A:
            temp = [0] * 26
            for ch in string:
                temp[ord(ch) - 97] += 1
            for i in range(26):
                chars[i] = min(chars[i], temp[i])
        ans = []
        for i in range(26):
            if chars[i] > 0:
                ans.extend([chr(i + 97)] * chars[i])
        return ans
