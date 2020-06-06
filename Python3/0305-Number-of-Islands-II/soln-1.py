class Solution:
    def numIslands2(self, m: int, n: int, positions: List[List[int]]) -> List[int]:
        parents = {}
        cnt = 0
        def find(x):
            if parents[x] == x:
                return x
            parents[x] = find(parents[x])
            return parents[x]
        ans = []
        for r, c in positions:
            if (r, c) in parents:
                ans.append(cnt)
                continue
            parents[(r, c)] = (r, c)
            cnt += 1
            for nr, nc in (r - 1, c), (r + 1, c), (r, c - 1), (r, c + 1):
                if 0 <= nr < m and 0 <= nc < n:
                    if (nr, nc) in parents:
                        rx = find((r, c))
                        ry = find((nr, nc))
                        if rx != ry:
                            parents[rx] = ry
                            cnt -= 1
            ans.append(cnt)
        return ans
