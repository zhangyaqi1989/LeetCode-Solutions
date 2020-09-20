class Solution:
    def unhappyFriends(self, n: int, preferences: List[List[int]], pairs: List[List[int]]) -> int:
        idxes = [[-1] * n for _ in range(n)]
        for i, prefs in enumerate(preferences):
            for idx, friend in enumerate(prefs):
                idxes[i][friend] = idx
        ps = [-1] * n
        for x, y in pairs:
            ps[x] = y
            ps[y] = x
        cnt = 0
        for x in range(n):
            y = ps[x]
            cnt += any(idxes[x][u] < idxes[x][y] and idxes[u][x] < idxes[u][ps[u]] for u in range(n) if u != x)
        return cnt
