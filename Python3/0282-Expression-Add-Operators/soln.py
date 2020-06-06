class Solution:
    def addOperators(self, num, target):
        """
        :type num: str
        :type target: int
        :rtype: List[str]
        """
        ans = []
        for i in range(1, len(num) + 1):
            if i == 1 or (i > 1 and num[0] != '0'):
                self.dfs(num[i:], num[:i], int(num[:i]), int(num[:i]), ans, target)
        return ans
    def dfs(self, num, temp, cur, last, ans, target):
        if not num:
            if cur == target:
                ans.append(temp)
            return
        for i in range(1, len(num) + 1):
            s_val = num[:i]
            val = int(s_val)
            if i == 1 or (i > 1 and num[0] != '0'):
                self.dfs(num[i:], temp + '+' + s_val, cur + val, val, ans, target)
                self.dfs(num[i:], temp + '-' + s_val, cur - val, -val, ans, target)
                self.dfs(num[i:], temp + '*' + s_val, cur - last + last * val, last * val, ans, target)