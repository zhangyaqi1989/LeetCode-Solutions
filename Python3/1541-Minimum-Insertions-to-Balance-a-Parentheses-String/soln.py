class Solution:
    def minInsertions(self, s: str) -> int:
        nlefts = 0
        ans = 0
        n = len(s)
        for ch, g in itertools.groupby(s):
            cnt = len(list(g))
            if ch == '(':
                nlefts += cnt
            else:
                if cnt % 2 == 1:
                    ans += 1
                ncloses = (cnt + 1) // 2
                if nlefts < ncloses:
                    ans += ncloses - nlefts
                    nlefts = ncloses
                nlefts -= ncloses
        return ans + nlefts * 2
