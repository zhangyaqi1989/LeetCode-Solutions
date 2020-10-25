class Solution:
    def maxLengthBetweenEqualCharacters(self, s: str) -> int:
        last_idxes = [-1] * 26
        ans = -1
        for i, ch in enumerate(s):
            val = ord(ch) - ord('a')
            if last_idxes[val] != -1:
                temp = i - last_idxes[val] - 1
                ans = max(ans, temp)
            else:
                last_idxes[val] = i
        return ans
