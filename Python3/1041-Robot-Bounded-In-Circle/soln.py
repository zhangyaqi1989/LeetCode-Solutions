class Solution:
    def isRobotBounded(self, instructions: str) -> bool:
        cur = 0
        face = 1j
        cnt = 0
        seen = collections.defaultdict(set)
        n = len(instructions)
        for ch in itertools.cycle(instructions):
            if cnt == 100000:
                break
            if ch == 'G':
                cur += face
            elif ch == 'L':
                face *= 1j
            else:
                face *= -1j
            if (cnt % n) in seen[(cur, face)]:
                return True
            seen[(cur, face)].add(cnt % n)
            cnt += 1
        return False
        
