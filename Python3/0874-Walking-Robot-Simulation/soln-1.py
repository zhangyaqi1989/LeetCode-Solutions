class Solution:
    def robotSim(self, commands: List[int], obstacles: List[List[int]]) -> int:
        obstacles = {complex(*ob) for ob in obstacles}
        ans = 0
        pos = 0 + 0j
        heading = 1j
        for command in commands:
            if command == -2:
                heading *= 1j
            elif command == -1:
                heading *= -1j
            else:
                for _ in range(command):
                    pos += heading
                    if pos in obstacles:
                        pos -= heading
                        break
                    else:
                        ans = max(ans, pos.imag * pos.imag + pos.real * pos.real)
        return int(ans)

