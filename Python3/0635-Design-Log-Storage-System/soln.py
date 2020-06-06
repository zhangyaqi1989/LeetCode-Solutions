ass LogSystem:

    def __init__(self):
        self.gra_d = {'Year'   : 4,
                      'Month'  : 7,
                      'Day'    : 10,
                      'Hour'   : 13,
                      'Minute' : 16,
                      'Second' : 19}
        self.logs = []
        

    def put(self, id, timestamp):
        """
        :type id: int
        :type timestamp: str
        :rtype: void
        """
        self.logs.append((id, timestamp))

    def retrieve(self, s, e, gra):
        """
        :type s: str
        :type e: str
        :type gra: str
        :rtype: List[int]
        """
        print(self.logs)
        idx = self.gra_d[gra]
        s = s[:idx]
        e = e[:idx]
        return [i for i, stamp in self.logs if s <= stamp[:idx] <= e]
        


# Your LogSystem object will be instantiated and called as such:
# obj = LogSystem()
# obj.put(id,timestamp)
# param_2 = obj.retrieve(s,e,gra)
