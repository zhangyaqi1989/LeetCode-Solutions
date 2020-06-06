class Solution:
    def reverseOnlyLetters(self, S):
        """
        :type S: str
        :rtype: str
        """
        lst = list(S)
        l, r = 0, len(lst) - 1
        while l < r:
            while l < r and not lst[l].isalpha():
                l += 1
            while l < r and not lst[r].isalpha():
                r -= 1
            if l < r:
                lst[l], lst[r] = lst[r], lst[l]
                l, r = l + 1, r - 1
        return ''.join(lst)