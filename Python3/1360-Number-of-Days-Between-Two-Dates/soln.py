import datetime
class Solution:
    def daysBetweenDates(self, date1: str, date2: str) -> int:
        d1 = datetime.date(*(map(int, date1.split('-'))))
        d2 = datetime.date(*(map(int, date2.split('-'))))
        return abs((d1 - d2).days)
