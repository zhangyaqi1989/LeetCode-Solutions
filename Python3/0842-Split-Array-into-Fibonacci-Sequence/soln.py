class Solution:
    def splitIntoFibonacci(self, S):
        """
        :type S: str
        :rtype: List[int]
        """
        def split_to_fib(i, j):
            ""
            a = S[:i]
            b = S[i:j]
            if self.valid(a) and self.valid(b):
                a, b = int(a), int(b)
                ans = [a, b]
                while j < len(S):
                    c = a + b
                    if c > (1 << 31) - 1:
                        return []
                    c_str = str(c)
                    if c_str == S[j : j + len(c_str)]:
                        a, b = b, c
                        ans.append(c)
                        j += len(c_str)
                    else:
                        return []
                return ans
            else:
                return []
        for i in range(1, len(S)):
            for j in range(i + 1, len(S)):
                subs = split_to_fib(i, j)
                if subs:
                    return subs
        return []
    
    def valid(self, sub):
        "Check if sub string is valid."
        return not ((len(sub) > 1 and sub[0] == '0') or
                    int(sub) > (1 << 31) - 1)
            