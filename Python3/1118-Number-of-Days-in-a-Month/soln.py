class Solution:
    def numberOfDays(self, Y: int, M: int) -> int:
        def is_leap_year(year):
            return (year % 4 == 0 and year % 100 != 0) or year % 400 == 0
        days = [0,31,28,31,30,31,30,31,31,30,31,30,31]
        if M == 2:
            return 29 if is_leap_year(Y) else 28
        else:
            return days[M]
