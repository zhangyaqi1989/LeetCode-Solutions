class Solution:
    def sequentialDigits(self, low: int, high: int) -> List[int]:
        mx_len = len(str(high))
        ans = []
        def dfs(cur, last, cur_len, mx_len, ans):
            if low <= cur <= high:
                ans.append(cur)
            if cur_len < mx_len and last != 9:
                dfs(cur * 10 + last + 1, last + 1, cur_len + 1, mx_len, ans)
        for i in range(1, 10):
            dfs(i, i, 1, mx_len, ans)
        ans.sort()
        return ans
