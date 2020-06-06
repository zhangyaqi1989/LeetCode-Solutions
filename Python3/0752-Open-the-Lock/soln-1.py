class Solution:
    def openLock(self, deadends: List[str], target: str) -> int:
        deadends = set([tuple(map(int, deadend)) for deadend in deadends])
        target = tuple(map(int, target))
        if (0, 0, 0, 0) in deadends or target in deadends:
            return -1
        s1, s2 = {(0, 0, 0, 0)}, {target}
        seen = s1 & s2
        step = 0
        while s1 and s2:
            if s2 < s1:
                s1, s2 = s2, s1
            step += 1
            s = set()
            for state in s1:
                for i, val in enumerate(state):
                    new_states = (state[:i] + ((val + 1) % 10,) + state[i + 1:], state[:i] + ((val - 1) % 10,) + state[i + 1:])
                    for new_state in new_states:
                        if new_state in s2:
                            return step
                        if new_state not in deadends and new_state not in seen:
                            seen.add(new_state)
                            s.add(new_state)
            s1 = s
        return -1
                    
