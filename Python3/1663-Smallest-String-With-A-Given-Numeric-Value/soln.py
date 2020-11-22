class Solution:
    def getSmallestString(self, n: int, k: int) -> str:
        # len = n, numerical value = k
        d = {i: ch for i, ch in enumerate(string.ascii_lowercase, 1)}
        d[0] = 'z'
        ans = []
        for i in range(n):
            left = n - i
            if 1 + 26 * (left - 1) >= k:
                ans.append('a')
                k -= 1
            else:
                ch = d[k % 26]
                ans.append(ch)
                k -= k % 26
        return ''.join(ans)
