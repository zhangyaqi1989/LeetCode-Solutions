class Solution(object):
    def shortestSuperstring(self, A):
        """
        :type A: List[str]
        :rtype: str
        """
        def overlap(w1, w2):
            n1, n2 = len(w1), len(w2)
            ans = 0
            s = ''
            for i in range(1, min(n1, n2) + 1):
                if w1[-i:] == w2[:i]:
                    if ans < i:
                        ans = i
                        s = w1 + w2[i:]
            for i in range(1, min(n1, n2) + 1):
                if w2[-i:] == w1[:i]:
                    if ans < i:
                        ans = i
                        s = w2 + w1[i:]
            return (ans, s) if ans > 0 else (ans, w1 + w2)
        A = set(A)
        while len(A) != 1:
            l, s = float('-inf'), None
            x, y = None, None
            for a, b in itertools.combinations(A, 2):
                l_temp, s_temp = overlap(a, b)
                if l_temp > l:
                    l = l_temp
                    s = s_temp
                    x, y = a, b
            A.remove(x)
            A.remove(y)
            A.add(s)
        return A.pop()