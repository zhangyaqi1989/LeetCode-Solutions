class Solution:
    def distanceBetweenBusStops(self, distance: List[int], start: int, destination: int) -> int:
        if start > destination:
            start, destination = destination, start
        ans = sum(distance[stop] for stop in range(start, destination))
        return min(ans, sum(distance) - ans)
