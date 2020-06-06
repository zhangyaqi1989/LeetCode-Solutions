class Solution:
    def carFleet(self, target: int, position: List[int], speed: List[int]) -> int:
        pairs = [(target - p, s) for p, s in zip(position, speed)]
        time, cnt = -1, 0
        for d, s in sorted(pairs):
            arrive = d / s
            if arrive > time:
                time = arrive
                cnt += 1
        return cnt
