class Solution:
    def confusingNumber(self, N: int) -> bool:
        chars = list(str(N))
        if any(ch in chars for ch in "23457"):
            return False
        d = dict(zip('01689', '01986'))
        ans = []
        for i in reversed(range(len(chars))):
            ans.append(d[chars[i]])
        return ans != chars
