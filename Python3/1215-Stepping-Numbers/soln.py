class Solution:
    def countSteppingNumbers(self, low: int, high: int) -> List[int]:
        high_str = str(high)
        def dfs(digits):
            if len(digits) > len(high_str):
                return
            num = int(''.join(map(str, digits)))
            if low <= num <= high:
                self.ans.append(num)
            last = digits[-1]
            if last + 1 <= 9:
                digits.append(last + 1)
                dfs(digits)
                digits.pop()
            if last - 1 >= 0:
                digits.append(last - 1)
                dfs(digits)
                digits.pop()
        self.ans = []
        for i in range(10):
            dfs([i])
        return sorted(set(self.ans))
