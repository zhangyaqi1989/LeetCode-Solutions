class Solution:
    def minSteps(self, s: str, t: str) -> int:
        s_chars, t_chars = [0] * 26, [0] * 26
        for ch in s:
            s_chars[ord(ch) - ord('a')] += 1
        for ch in t:
            t_chars[ord(ch) - ord('a')] += 1
        return len(s) - sum(min(cnt, t_chars[i]) for i, cnt in enumerate(s_chars))
