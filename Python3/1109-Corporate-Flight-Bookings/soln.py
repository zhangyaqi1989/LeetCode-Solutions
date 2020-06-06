class Solution:
    def corpFlightBookings(self, bookings: List[List[int]], n: int) -> List[int]:
        counter = [0] * (n + 2)
        for i, j, k in bookings:
            counter[i] += k
            counter[j + 1] -= k
        ans = []
        cnt = 0
        for i in range(1, n + 1):
            cnt += counter[i]
            ans.append(cnt)
        return ans
