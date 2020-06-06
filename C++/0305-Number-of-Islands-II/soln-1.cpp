class Solution:
    def numIslands2(self, m: int, n: int, positions: List[List[int]]) -> List[int]:
        def find(x):
            if x == parents[x]:
                return parents[x]
            else:
                parents[x] = find(parents[x])
                return parents[x]
        ans = []
        cnt = 0
        parents = list(range(m * n))
        ones = set()
        for i, j in positions:
            if (i, j) in ones:
                ans.append(cnt)
                continue
            ones.add((i, j))
            cnt += 1
            x = i * n + j
            rx = find(x)
            for ni, nj in (i - 1, j), (i + 1, j), (i, j - 1), (i, j + 1):
                if 0 <= ni < m and 0 <= nj < n and (ni, nj) in ones:
                    y = ni * n + nj
                    ry = find(y)
                    if rx != ry:
                        parents[ry] = rx
                        cnt -= 1
            ans.append(cnt)
        return ans
