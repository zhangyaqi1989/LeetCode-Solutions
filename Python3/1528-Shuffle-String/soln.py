class Solution:
    def restoreString(self, s: str, indices: List[int]) -> str:
        ans = [''] * len(s)
        for idx, ch in zip(indices, s):
            ans[idx] = ch
        return ''.join(ans)
