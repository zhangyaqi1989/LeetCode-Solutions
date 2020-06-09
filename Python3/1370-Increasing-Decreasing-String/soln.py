class Solution:
    def sortString(self, s: str) -> str:
        ans = []
        n = len(s)
        cnts = [0] * 26
        ctoi = lambda ch : ord(ch) - ord('a')
        itoc = lambda i: chr(ord('a') + i)
        for ch in s:
            cnts[ctoi(ch)] += 1
        while len(ans) < n:
            for i in range(26):
                if cnts[i]:
                    cnts[i] -= 1
                    ans.append(itoc(i))
            for i in reversed(range(26)):
                if cnts[i]:
                    cnts[i] -= 1
                    ans.append(itoc(i))
        return ''.join(ans)
