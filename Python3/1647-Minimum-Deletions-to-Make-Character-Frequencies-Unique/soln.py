class Solution:
    def minDeletions(self, s: str) -> int:
        counter = [0] * 26
        for ch in s:
            counter[ord(ch) - ord('a')] += 1
        counter.sort(reverse=True)
        ans = 0
        for i, cnt in enumerate(counter):
            if cnt == 0:
                continue
            if i > 0 and counter[i - 1] <= cnt:
                move_to = max(0, counter[i - 1] - 1)
                counter[i] = move_to
                ans += cnt - move_to
        return ans
