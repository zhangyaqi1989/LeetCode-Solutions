class Solution:
    def carFleet(self, target, position, speed):
        """
        :type target: int
        :type position: List[int]
        :type speed: List[int]
        :rtype: int
        """
        if not position: return 0
        pairs = sorted([(p, s) for p, s in zip(position, speed)], reverse=True)
        times = [(target - p) / s for p, s in pairs]
        cnt = 1
        fleet_time = times[0]
        for time in times:
            if time > fleet_time:
                cnt += 1
                fleet_time = time
        return cnt