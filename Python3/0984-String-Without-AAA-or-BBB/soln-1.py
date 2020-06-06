class Solution:
    def strWithout3a3b(self, A: int, B: int) -> str:
        # greedy
        a, b = 'a', 'b'
        if A < B:
            a, b = b, a
            A, B = B, A
        # A >= B
        ans = ''
        r = A - (B + 1)
        lst = []
        cnt = 0
        twos = 0
        while A > 0 or B > 0:
            if cnt % 2 == 0:
                if twos < r:
                    lst.append(a * 2)
                    twos += 1
                    A -= 2
                else:
                    lst.append(a)
                    A -= 1
            else:
                lst.append(b)
                B -= 1
            cnt += 1
        return ''.join(lst)
        
