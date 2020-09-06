class Solution:
    def modifyString(self, s: str) -> str:
        def pick_char(blacklist):
            for ch in string.ascii_lowercase:
                if ch not in blacklist:
                    return ch
        ans = []
        for i, ch in enumerate(s):
            if ch != '?':
                ans.append(ch)
            else:
                blacklist = set()
                if ans:
                    blacklist.add(ans[-1])
                if i + 1 < len(s) and s[i + 1] != '?':
                    blacklist.add(s[i + 1])
                ans.append(pick_char(blacklist))
        return ''.join(ans)
