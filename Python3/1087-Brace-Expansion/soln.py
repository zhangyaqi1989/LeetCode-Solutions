class Solution:
    def permute(self, S: str) -> List[str]:
        ans = [""]
        i = 0
        n = len(S)
        while i < n:
            j = S.find('{', i)
            if j == -1:
                add = S[i:]
                ans = [item + add for item in ans]
                break
            else:
                add = S[i:j]
                jj = S.find('}', j + 1)
                tokens = S[j + 1:jj].split(',')
                if tokens:
                    ans = [item + add + opt for item in ans for opt in tokens]
                i = jj + 1
        return sorted(ans)
