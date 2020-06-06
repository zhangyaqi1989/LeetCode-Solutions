class Solution:
    def gridIllumination(self, N: int, lamps: List[List[int]], queries: List[List[int]]) -> List[int]:
        ones = set()
        locs = collections.defaultdict(set)
        for x, y in lamps:
            ones.add((x, y))
            locs[0, x].add((x, y))
            locs[1, y].add((x, y))
            locs[2, x + y].add((x, y))
            locs[3, x - y].add((x, y))
        ans = []
        for x, y in queries:
            for item in (0, x), (1, y), (2, x + y), (3, x - y):
                if item in locs:
                    ans.append(1)
                    break
            else:
                ans.append(0)
            for dx in (-1, 0, 1):
                for dy in (-1, 0, 1):
                    if dx == 0 == dy:
                        continue
                    newx, newy = x + dx, y + dy
                    if (newx, newy) in ones:
                        for item in (0, newx), (1, newy), (2, newx + newy), (3, newx - newy):
                            if item in locs:
                                locs[item].discard((newx, newy))
                                if len(locs[item]) == 0:
                                    locs.pop(item)
        return ans
