class Solution:
    def nthUglyNumber(self, n):
        """
        :type n: int
        :rtype: int
        """
        i2 = i3 = i5 = 0
        ans = [1]
        while len(ans) < n:
            while ans[i2] * 2 <= ans[-1]:
                i2 += 1
            while ans[i3] * 3 <= ans[-1]:
                i3 += 1
            while ans[i5] * 5 <= ans[-1]:
                i5 += 1
            item = min(ans[i2] * 2, ans[i3] * 3, ans[i5] * 5)
            ans.append(item)
        return ans[-1]