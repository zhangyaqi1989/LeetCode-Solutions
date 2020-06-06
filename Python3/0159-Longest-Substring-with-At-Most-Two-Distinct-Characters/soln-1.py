class Solution:
    def lengthOfLongestSubstringTwoDistinct(self, s):
        """
        :type s: str
        :rtype: int
        """
        # we can use ch1 and ch2 to keep track of two characters
        # curch keeps track of last seen character
        ch1, ch2, curch = None, None, None
        cnt1, cnt2, curcnt, ans = 0, 0, 0, 0
        for ch in s:
            if ch1 == None or ch1 == ch:
                ch1 = ch
                cnt1 += 1
            elif ch2 == None or ch2 == ch:
                ch2 = ch
                cnt2 += 1
            else:
                length = cnt1 + cnt2
                ans = max(ans, length)
                ch1, ch2 = curch, ch
                cnt1, cnt2 = curcnt, 1
            if ch == curch:
                curcnt += 1
            else:
                curch = ch
                curcnt = 1
        return max(ans, cnt1 + cnt2)