class Solution:
    def numKLenSubstrNoRepeats(self, S: str, K: int) -> int:
        window = collections.Counter()
        n = len(S)
        cnt = 0
        for i, ch in enumerate(S):
            window[ch] += 1
            if i >= K:
                left_ch = S[i - K]
                window[left_ch] -= 1
                if not window[left_ch]:
                    window.pop(left_ch)
            if i >= K - 1:
                if len(window) == K:
                    cnt += 1
        return cnt
