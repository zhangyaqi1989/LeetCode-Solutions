class Solution:
    def slowestKey(self, releaseTimes: List[int], keysPressed: str) -> str:
        durations = [0] * 26
        start_time = 0
        for time, key in zip(releaseTimes, keysPressed):
            idx = ord(key) - ord('a')
            durations[idx] = max(durations[idx], time - start_time)
            start_time = time
        idx, mx_time = 0, durations[0]
        for i, time in enumerate(durations):
            if time >= mx_time:
                mx_time = time
                idx = i
        return chr(ord('a') + idx)
