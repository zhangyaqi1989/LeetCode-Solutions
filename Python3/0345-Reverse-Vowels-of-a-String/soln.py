class Solution:
    def reverseVowels(self, s):
        """
        :type s: str
        :rtype: str
        """
        lst = list(s)
        l, r = 0, len(s) - 1
        while l < r:
            while l < r and s[l] not in 'aeiouAEIOU':
                l += 1
            while l < r and s[r] not in 'aeiouAEIOU':
                r -= 1
            if l >= r: break
            lst[l], lst[r] = lst[r], lst[l]
            l, r = l + 1, r - 1
        return ''.join(lst)