class Solution:
    def maxVacationDays(self, flights, days):
        """
        :type flights: List[List[int]]
        :type days: List[List[int]]
        :rtype: int
        """
        n, k = len(days), len(days[0]) # n cities, k, weeks
        max_vacation = [0] + [float('-inf')] * (n - 1)
        flights_avi = {}
        for dep_city in range(n):
            flights_avi[dep_city] = [arr_city for arr_city, exists in enumerate(flights[dep_city]) if exists or dep_city == arr_city]
        for week in range(k):
            cur = [float('-inf')] * n
            for dep_city in range(n):
                for arr_city in flights_avi[dep_city]:
                    cur[arr_city] = max(cur[arr_city], max_vacation[dep_city] + days[arr_city][week])
            max_vacation = cur
        return max(max_vacation)