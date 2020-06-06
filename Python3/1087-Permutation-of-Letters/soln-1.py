class Solution:
    def permute(self, S: str) -> List[str]:
        # "{a,b}c{d,e}f"
        ans = [""]
        i, n = 0, len(S)
        while i < n:
            j = S.find('{', i)
            if j == -1:
                add = S[i:]
                ans = [item + add for item in ans]
                break
            else:
                jj = S.find('}', j + 1)
                add = S[i:j]
                tokens = S[j + 1:jj].split(',')
                ans = [item + add + token for item in ans for token in tokens]
                i = jj + 1
        return sorted(ans)
