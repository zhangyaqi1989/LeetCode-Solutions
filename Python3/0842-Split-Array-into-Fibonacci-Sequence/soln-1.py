class Solution:
    def splitIntoFibonacci(self, S: str) -> List[int]:
        # "123456579"
        def valid(s):
            # check if s can convert to a valid number
            if s:
                num = int(s)
                if num != 0 and s.startswith('0'):
                    return False
                if num > 2 ** 31 - 1:
                    return False
                return True
            else:
                return False
        n = len(S)
        for i in range(1, n):
            for j in range(i + 1, n):
                a, b = S[:i], S[i:j]
                if valid(a) and valid(b):
                    a, b = int(a), int(b)
                    k = j
                    ans = [a, b]
                    while k < n:
                        c = a + b
                        if c > 2 ** 31 - 1:
                            break
                        str_c = str(c)
                        len_c = len(str_c)
                        if k + len_c <= n and S[k:k+len_c] == str_c:
                            k = k + len_c
                            a, b = b, c
                            ans.append(c)
                        else:
                            break
                    else:
                        return ans
        return []
