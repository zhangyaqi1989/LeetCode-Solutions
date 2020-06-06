class Solution:
    def isRobotBounded(self, instructions: str) -> bool:
        d = 1j
        p = 0
        for ins in instructions:
            if ins == "L":
                d = d * 1j
            elif ins == 'R':
                d = d * (-1j)
            else:
                p += d
        return False if (d == 1j and p != 0) else True
