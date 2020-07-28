class Solution:
    def numKLenSubstrNoRepeats(self, S: str, K: int) -> int:
        window = [0] * 26
        ans = 0
        cnt = 0
        for i, ch in enumerate(S):
            window[ord(ch) - ord('a')] += 1
            if window[ord(ch) - ord('a')] == 1:
                cnt += 1
            if i >= K:
                left_ch = S[i - K]
                window[ord(left_ch) - ord('a')] -= 1
                if window[ord(left_ch) - ord('a')] == 0:
                    cnt -= 1
            if cnt == K:
                ans += 1
        return ans
