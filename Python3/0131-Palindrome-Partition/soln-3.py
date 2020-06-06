class Solution:
    def partition(self, s: str) -> List[List[str]]:
        valids = set()
        n = len(s)
        for i in range(n):
            for l, r in (i, i), (i, i + 1):
                while l >= 0 and r < n and s[l] == s[r]:
                    valids.add((l, r))
                    l -= 1
                    r += 1
        ans = []
        def dfs(lo, cand):
            if lo == len(s):
                ans.append(cand[:])
            else:
                for i in range(lo, len(s)):
                    if (lo, i) in valids:
                        cand.append(s[lo:i + 1])
                        dfs(i + 1, cand)
                        cand.pop()
        dfs(0, [])
        return ans
