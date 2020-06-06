class Solution:
    def removeKdigits(self, num: str, k: int) -> str:
        picked = []
        for ch in num:
            while k > 0 and picked and picked[-1] > ch:
                picked.pop()
                k -= 1
            picked.append(ch)
        if k > 0:
            ans = ''.join(picked[:-k]).lstrip('0')
        else:
            ans = ''.join(picked).lstrip('0')
        return ans if ans else "0"
