class Solution:
    def racecar(self, target: int) -> int:
        def move(pos, speed):
            yield pos + speed, speed * 2
            yield (pos, -1) if speed > 0 else (pos, 1)
        frontier = collections.deque([(0, 1)])
        seen = {(0, 1)}
        cnt = 0
        while frontier:
            sz = len(frontier)
            for i in range(sz):
                pos, speed = frontier.popleft()
                if pos == target:
                    return cnt
                if abs(pos) > 20000:
                    continue
                for new_state in move(pos, speed):
                    if new_state not in seen:
                        seen.add(new_state)
                        frontier.append(new_state)
            cnt += 1
