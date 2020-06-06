class Cashier:

    def __init__(self, n: int, discount: int, products: List[int], prices: List[int]):
        self.cnt = 0
        self.n = n
        self.dis = discount
        self.ps = dict(zip(products, prices))
        
        

    def getBill(self, product: List[int], amount: List[int]) -> float:
        self.cnt += 1
        price = sum(self.ps[p] * a for p, a in zip(product, amount))
        if self.cnt == self.n:
            self.cnt = 0
            price = price * (100 - self.dis) / 100.0
        return price


# Your Cashier object will be instantiated and called as such:
# obj = Cashier(n, discount, products, prices)
# param_1 = obj.getBill(product,amount)
