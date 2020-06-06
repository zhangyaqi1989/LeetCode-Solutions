class Solution:
    def wordsAbbreviation(self, words: List[str]) -> List[str]:
        def compute_LCP(w1, w2):
            cnt = 0
            for i, (c1, c2) in enumerate(zip(w1, w2)):
                if c1 == c2:
                    cnt += 1
                else:
                    break
            return cnt
        groups = collections.defaultdict(list)
        for i, w in enumerate(words):
            groups["{:s}{:d}{:s}".format(w[0], len(w) - 2, w[-1])].append((w, i))
        ans = [None] * len(words)
        for code, lst in groups.items():
            lst.sort()
            n = len(lst)
            lcps = [0] * n
            for i in range(n):
                if i > 0:
                    lcp = compute_LCP(lst[i - 1][0], lst[i][0])
                    lcps[i] = max(lcp, lcps[i])
                    lcps[i - 1] = max(lcp, lcps[i - 1])
            for lcp, (w, i) in zip(lcps, lst):
                code = w[:lcp + 1]
                if lcp + 2 < len(w):
                    code += str(len(w) - lcp - 2)
                code += w[-1]
                if len(code) < len(w):
                    ans[i] = code
                else:
                    ans[i] = w
        return ans
