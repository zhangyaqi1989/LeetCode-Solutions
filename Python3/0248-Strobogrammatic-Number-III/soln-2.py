class Solution:
    def strobogrammaticInRange(self, low: str, high: str) -> int:
        # generate
        mn, mx = len(low), len(high)
        def generate(n):
            """generate strobogrammatic number has n digits."""
            ans = ['0', '1', '8'] if n % 2 else ['']
            pairs = ['00', '11', '88', '69', '96']
            while n > 1:
                if n - 2 > 1:
                    ans = [l + item + r for item in ans for l, r in pairs]
                else:
                    ans = [l + item + r for item in ans for l, r in pairs[1:]]
                n -= 2
            return ans
        def check(num):
            if len(num) < len(low) or len(num) > len(high):
                return False
            return (len(num) > len(low) or num >= low) and (len(num) < len(high) or num <= high)
        ans = set()
        for i in range(mn, mx + 1):
            ans.update({item for item in generate(i) if check(item)})
        return len(ans)
