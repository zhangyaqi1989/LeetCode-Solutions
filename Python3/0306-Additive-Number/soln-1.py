class Solution:
    def isAdditiveNumber(self, num: str) -> bool:
        n = len(num)
        for i in range(1, n - 1):
            if i != 1 and num[0] == '0':
                continue
            for j in range(i + 1, n):
                if j != i + 1 and num[i] == '0':
                    continue
                a = int(num[:i])
                b = int(num[i:j])
                idx = j
                while idx != n:
                    c = a + b
                    str_c = str(c)
                    if num[idx:idx + len(str_c)] != str_c:
                        break
                    a, b = b, c
                    idx = idx + len(str_c)
                else:
                    return True
        return False
