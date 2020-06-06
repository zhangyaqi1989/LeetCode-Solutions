class ProductOfNumbers:

    def __init__(self):
        self.pres = [1]
        self.last_zero = -1
        self.cnt = 0
        
        

    def add(self, num: int) -> None:
        if num != 0:
            self.pres.append(self.pres[-1] * num)
        else:
            self.last_zero = self.cnt
            self.pres.append(1)
        self.cnt += 1
        

    def getProduct(self, k: int) -> int:
        left = self.cnt - k
        if self.last_zero >= left:
            return 0
        else:
            return self.pres[-1] // self.pres[-1 - k]
        


# Your ProductOfNumbers object will be instantiated and called as such:
# obj = ProductOfNumbers()
# obj.add(num)
# param_2 = obj.getProduct(k)
