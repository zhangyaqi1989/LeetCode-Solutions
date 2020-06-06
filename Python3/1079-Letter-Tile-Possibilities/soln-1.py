import functools
class Solution:
    def numTilePossibilities(self, tiles: str) -> int:
        return len(functools.reduce(operator.or_, [set(itertools.permutations(tiles, i)) for i in range(1, len(tiles) + 1)]))
