class Solution:
    def countTriplets(self, A: 'List[int]') -> 'int':
        v = [-1] * (1 << 16)
        ans = 0
        for i in A:
            for j in A:
                s = i & j
                if v[s] == -1:
                    cnt = 0
                    for c in A:
                        if (s & c) == 0:
                            cnt += 1
                    v[s] = cnt
                    ans += cnt
                else:
                    ans += v[s]
        return ans
