class Solution:
    def getSmallestString(self, n: int, k: int) -> str:
        # len = n, numerical value = k
        ans = []
        for i in range(n):
            left = n - i
            if 1 + 26 * (left - 1) >= k:
                ans.append('a')
                k -= 1
            else:
                q, r = divmod(k, 26)
                if q == left - 1:
                    ans.append(chr(ord('a') + k % 26 - 1))
                    ans.append('z' * (left - 1))
                else:
                    ans.append('z' * left)
                break
        return ''.join(ans)
