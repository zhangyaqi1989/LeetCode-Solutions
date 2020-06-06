class Solution:
    def removeKdigits(self, num: str, k: int) -> str:
        keep = []
        for ch in num:
            while keep and ch < keep[-1] and k:
                keep.pop()
                k -= 1
            keep.append(ch)
        if k > 0:
            keep = keep[:-k]
        ans = ''.join(keep).lstrip('0')
        return ans if ans else "0"
