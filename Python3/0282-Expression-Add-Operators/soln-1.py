class Solution:
    def addOperators(self, num: str, target: int) -> List[str]:
        ans = []
        for i in range(1, len(num) + 1):
            if i > 1 and num[0] == '0':
                continue
            self.dfs(num, i, num[:i], int(num[:i]), int(num[:i]), target, ans)
        return ans
        
    def dfs(self, num, idx, expr, cur, last, target, ans):
        if idx == len(num):
            if cur == target:
                ans.append(expr)
        else:
            for i in range(idx + 1, len(num) + 1):
                if i - idx > 1 and num[idx] == '0':
                    continue
                else:
                    val = int(num[idx:i])
                    self.dfs(num, i, expr + "+{}".format(num[idx:i]), cur + val, val, target, ans)
                    self.dfs(num, i, expr + "-{}".format(num[idx:i]), cur - val, -val, target, ans)
                    self.dfs(num, i, expr + "*{}".format(num[idx:i]), cur - last + last * val, last * val, target, ans)
        
