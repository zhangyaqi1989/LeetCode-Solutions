class Solution:
    def racecar(self, target: int) -> int:
        def neighbor(pos, speed):
            yield pos + speed, speed * 2
            yield pos, (1 if speed < 0 else -1)
        frontier = [(0, 1)]
        levels = {(0, 1) : 0}
        i = 0
        while frontier:
            nxt_level = []
            for p, s in frontier:
                if p == target:
                    return levels[p, s]
                for np, ns in neighbor(p, s):
                    if (np, ns) not in levels:
                        if abs(np) >= 20000:
                            continue
                        levels[(np, ns)] = i + 1
                        nxt_level.append((np, ns))
            frontier = nxt_level
            i += 1
