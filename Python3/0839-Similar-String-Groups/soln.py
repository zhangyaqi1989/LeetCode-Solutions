class Solution:
    def numSimilarGroups(self, A):
        """
        :type A: List[str]
        :rtype: int
        """
        def similar(i, j):
            "check if ith string and jth string is similar"
            cnt = 0
            for a, b in zip(A[i], A[j]):
                if a != b:
                    cnt += 1
                    if cnt > 2:
                        return False
            return True
        def find(x):
            if parents[x] == x:
                return x
            else:
                parents[x] = find(parents[x])
                return parents[x]
        N = len(A)
        parents = list(range(N))
        sizes = [1] * N
        groups = N
        for i in range(N):
            for j in range(i + 1, N):
                if similar(i, j):
                    ri = find(i)
                    rj = find(j)
                    if ri != rj:
                        groups -= 1
                        if sizes[ri] > sizes[rj]:
                            ri, rj = rj, ri
                        parents[ri] = rj
                        sizes[j] += sizes[i]
        return groups
