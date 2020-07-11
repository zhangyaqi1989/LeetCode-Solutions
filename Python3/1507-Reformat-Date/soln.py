class Solution:
    def reformatDate(self, date: str) -> str:
        month_idxes = {month : idx for idx, month in enumerate(["Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"], 1)}
        day, month, year = date.split()
        d = int(day[:-2])
        month = month_idxes[month]
        year = int(year)
        return f"{year}-{month:02d}-{d:02d}"
