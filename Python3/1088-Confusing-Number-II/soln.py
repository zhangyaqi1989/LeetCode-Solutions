class Solution:
    def helper(self, low, high):
        def generate_num(n):
            if n & 1:
                ans = ['0', '1', '8']
            else:
                ans = ['']
            pairs = ['00', '11', '88', '69', '96']
            while n > 1:
                n -= 2
                ans = [pair[0] + item + pair[1] for item in ans for pair in pairs[n<2:]]
            return list(map(int, ans))
        m, n = len(low), len(high)
        low, high = int(low), int(high)
        nums = []
        for i in range(m, n + 1):
            nums.extend(generate_num(i))
        return sum(low <= num <= high for num in nums)
    def confusingNumberII(self, N: int) -> int:
        # 1 and N
        bads = "23457"
        str_N = str(N + 1)
        n = len(str_N)
        ans = 0
        for i in range(1, n):
            ans += 4 * (5 ** (i - 1))
        goods = [0, 1, 6, 8, 9]
        for i, d in enumerate(str_N):
            start = 1 if i == 0 else 0
            d = int(d)
            for y in goods[start:]:
                if y >= d:
                    break
                ans += 5 ** (n - i - 1)
            if str(d) in bads:
                break
        same = self.helper(str(1), str(N))
        return ans - same
