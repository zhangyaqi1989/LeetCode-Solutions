class Solution:
    def numSplits(self, s: str) -> int:
        r_counter = [0] * 26
        l_counter = [0] * 26
        l = 0
        r = 0
        for ch in s:
            if r_counter[ord(ch) - ord('a')] == 0:
                r += 1
            r_counter[ord(ch) - ord('a')] += 1
        ans = 0
        for i, ch in enumerate(s):
            if r_counter[ord(ch) - ord('a')] == 1:
                r -= 1
            r_counter[ord(ch) - ord('a')] -= 1
            if l_counter[ord(ch) - ord('a')] == 0:
                l += 1
            l_counter[ord(ch) - ord('a')] += 1
            if r == l:
                ans += 1
        return ans
