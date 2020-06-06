class Solution:
    def getProbability(self, balls: List[int]) -> float:
        # possibility of two box have same number of distinct balls
        # state, akind, bkind, a - b
        def helper(k, n):
            # pick k from n
            ans = 1
            old_n = n
            for i in range(k):
                ans *= n
                n -= 1
            return ans / math.factorial(k) / (1 << old_n)
        dp = {(0, 0, 0) : 1}
        for num in balls:
            new_dp = {}
            # coeff
            for a in range(num + 1):
                b = num - a
                coeff = helper(a, num)
                for (akind, bkind, diff), prob in dp.items():
                    akind += a != 0
                    bkind += b != 0
                    diff += (a - b)
                    new_dp[akind, bkind, diff] = new_dp.get((akind, bkind, diff), 0.0) + prob * coeff
            dp = new_dp
            # print(dp)
        total = 0.0
        good = 0.0
        for (akind, bkind, diff), prob in dp.items():
            if diff == 0:
                total += prob
                if akind == bkind:
                    good += prob
        # print(good, total)
        return good / total
