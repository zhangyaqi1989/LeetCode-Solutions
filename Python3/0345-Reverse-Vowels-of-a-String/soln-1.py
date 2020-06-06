class Solution:
    def reverseVowels(self, s: str) -> str:
        ans = list(s)
        is_vowel = lambda ch : ch in 'aeiouAEIOU'
        lo, hi = 0, len(s) - 1
        while lo < hi:
            while lo < hi and not is_vowel(ans[lo]):
                lo += 1
            while lo < hi and not is_vowel(ans[hi]):
                hi -= 1
            if lo < hi:
                ans[lo], ans[hi] = ans[hi], ans[lo]
                lo += 1
                hi -= 1
        return ''.join(ans)
