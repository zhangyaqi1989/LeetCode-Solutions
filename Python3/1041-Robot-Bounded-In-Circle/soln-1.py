class Solution:
    def isRobotBounded(self, instructions: str) -> bool:
        cur = 0
        face = 1j
        for ch in instructions:
            if ch == 'G':
                cur += face
            elif ch == 'L':
                face *= 1j
            else:
                face *= -1j
        if face == 1j and cur != 0:
            return False
        return True
