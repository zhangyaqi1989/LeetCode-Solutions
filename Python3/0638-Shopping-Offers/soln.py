class Solution:
    def shoppingOffers(self, price, special, needs):
        """
        :type price: List[int]
        :type special: List[List[int]]
        :type needs: List[int]
        :rtype: int
        """
        memo = {}
        def helper(needs):
            if tuple(needs) in memo:
                return memo[tuple(needs)]
            cost = sum(p * need for p, need in zip(price, needs))
            for (*amounts, money) in special:
                if all(need >= amount for need, amount in zip(needs, amounts) ):
                    cur_cost = money + helper([need - amount for need, amount in zip(needs, amounts)])
                    if cur_cost < cost:
                        cost = cur_cost
            memo[tuple(needs)] = cost
            return cost
        return helper(needs)
