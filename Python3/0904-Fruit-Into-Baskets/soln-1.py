class Solution:
    def totalFruit(self, tree):
        """
        :type tree: List[int]
        :rtype: int
        """
        num1, num2, curnum = None, None, None
        cnt1, cnt2, curcnt, ans = 0, 0, 0, 0
        for num in tree:
            if num1 == None or num1 == num:
                num1 = num
                cnt1 += 1
            elif num2 == None or num2 == num:
                num2 = num
                cnt2 += 1
            else:
                ans = max(ans, cnt1 + cnt2)
                num1, num2 = curnum, num
                cnt1, cnt2 = curcnt, 1
            if curnum == num:
                curcnt += 1
            else:
                curnum = num
                curcnt = 1
        return max(ans, cnt1 + cnt2)