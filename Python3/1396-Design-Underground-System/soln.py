class UndergroundSystem:

    def __init__(self):
        self.ids = {}
        self.counter = collections.Counter()
        self.times = collections.Counter()
        

    def checkIn(self, id: int, stationName: str, t: int) -> None:
        self.ids[id] = (stationName, t)

    def checkOut(self, id: int, stationName: str, t: int) -> None:
        start_station, start_time = self.ids.pop(id)
        self.counter[(start_station, stationName)] += 1
        self.times[(start_station, stationName)] += t - start_time

    def getAverageTime(self, startStation: str, endStation: str) -> float:
        ticket = (startStation, endStation)
        return self.times[ticket] / self.counter[ticket]

# Your UndergroundSystem object will be instantiated and called as such:
# obj = UndergroundSystem()
# obj.checkIn(id,stationName,t)
# obj.checkOut(id,stationName,t)
# param_3 = obj.getAverageTime(startStation,endStation)
