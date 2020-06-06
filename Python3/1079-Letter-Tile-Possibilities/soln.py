class Solution:
    def numTilePossibilities(self, tiles: str) -> int:
        tiles = tuple(tiles)
        n = len(tiles)
        ans = set()
        for i in range(1, n + 1):
            ans.update(set(itertools.permutations(tiles, i)))
        return len(ans)
