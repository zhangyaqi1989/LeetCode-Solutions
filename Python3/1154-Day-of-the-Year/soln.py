class Solution:
    def dayOfYear(self, date: str) -> int:
        def is_leap(year):
            return (year % 4 == 0 and year % 100 != 0) or (year % 400 == 0)
        def days_in_month(year, month):
            if month in (1, 3, 5, 7, 8, 10, 12):
                return 31
            elif month == 2:
                return 29 if is_leap(year) else 28
            else:
                return 30
        year, month, day = map(int, date.split('-'))
        return day + sum(days_in_month(year, m) for m in range(1, month))
