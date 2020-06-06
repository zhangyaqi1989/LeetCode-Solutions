class Solution:
    def isRobotBounded(self, instructions: str) -> bool:
        position = 0
        direction = 1j
        for inst in instructions:
            if inst == 'G':
                position += direction
            elif inst == 'L':
                direction *= 1j
            else:
                direction *= (-1j)
        return position == 0 or direction != 1j
