class Solution:
    def maxNumOfSubstrings(self, s: str) -> List[str]:
        first = [-1] * 26
        last = [-1] * 26
        for i, ch in enumerate(s):
            idx = ord(ch) - ord('a')
            if first[idx] == -1:
                first[idx] = i
            last[idx] = i
        cands = set()
        for i in range(26):
            if first[i] != -1:
                start = first[i]
                end = last[i]
                mn = start
                mx = end
                for j in range(first[i], last[i] + 1):
                    ch = s[j]
                    mn = min(mn, first[ord(ch) - ord('a')])
                    mx = max(mx, last[ord(ch) - ord('a')])
                while start > mn or end < mx:
                    if start > mn:
                        ch = s[start]
                        start -= 1
                        mn = min(mn, first[ord(ch) - ord('a')])
                        mx = max(mx, last[ord(ch) - ord('a')])
                    if end < mx:
                        ch = s[end]
                        end += 1
                        mn = min(mn, first[ord(ch) - ord('a')])
                        mx = max(mx, last[ord(ch) - ord('a')])
                cands.add((start, end))
        cands = list(cands)
        cands.sort(key=lambda x : (x[1], x[1] - x[0], x[0]))
        lo = -1
        ans = []
        for start, end in cands:
            if start > lo:
                lo = end
                ans.append(s[start:end + 1])
        return ans if ans else [s]
