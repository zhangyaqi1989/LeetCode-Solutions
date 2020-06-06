class Cashier:

    def __init__(self, n: int, discount: int, products: List[int], prices: List[int]):
        self.cnt = 0
        self.n = n
        self.dis = discount
        self.prices = {prod : price for prod, price in zip(products, prices)}
        
        

    def getBill(self, product: List[int], amount: List[int]) -> float:
        self.cnt = (self.cnt + 1) % self.n
        money = sum(self.prices[p] * amt for p, amt in zip(product, amount))
        if self.cnt == 0:
            money -= (self.dis * money) / 100.0
        return money
        


# Your Cashier object will be instantiated and called as such:
# obj = Cashier(n, discount, products, prices)
# param_1 = obj.getBill(product,amount)
