class Solution:
    def minFlips(self, target: str) -> int:
        nflips = 0
        for ison in map(lambda x : x == '1', target):
            if ((not ison) and nflips % 2 == 1) or (ison and nflips % 2 == 0):
                nflips += 1
        return nflips
