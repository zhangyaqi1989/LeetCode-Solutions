class Solution:
    def minWindow(self, s: str, t: str) -> str:
        mn_len = math.inf
        ans = ""
        missing = collections.Counter(t)
        left = 0
        miss_types = len(set(t))
        for j, ch in enumerate(s):
            if ch in missing:
                missing[ch] -= 1
                if missing[ch] == 0:
                    miss_types -= 1
            if not miss_types:
                while left < j:
                    if s[left] in missing:
                        if missing[s[left]] < 0:
                            missing[s[left]] += 1
                        else:
                            break
                    left += 1
                if j - left + 1 < mn_len:
                    mn_len = j - left + 1
                    ans = s[left:j + 1]
        return ans
