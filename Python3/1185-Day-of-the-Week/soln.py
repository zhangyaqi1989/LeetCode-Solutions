import datetime
class Solution:
    def dayOfTheWeek(self, day: int, month: int, year: int) -> str:
        d = datetime.date(year, month, day)
        weekdays = ["Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"]
        return weekdays[d.weekday()]
