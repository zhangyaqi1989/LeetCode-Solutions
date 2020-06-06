class Solution:
    def robotSim(self, commands, obstacles):
        """
        :type commands: List[int]
        :type obstacles: List[List[int]]
        :rtype: int
        """
        obs = {complex(x, y) for x, y in obstacles}
        heading = 1j
        pos = 0
        ans = 0
        for command in commands:
            if command == -2:
                heading *= 1j
            elif command == -1:
                heading *= -1j
            else:
                for _ in range(command):
                    pos += heading
                    if pos in obs:
                        pos -= heading
                        break
                    else:
                        ans = max(ans, pos.real * pos.real + pos.imag * pos.imag)
        return round(ans)
