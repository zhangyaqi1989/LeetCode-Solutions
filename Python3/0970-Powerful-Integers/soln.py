class Solution:
    def powerfulIntegers(self, x, y, bound):
        """
        :type x: int
        :type y: int
        :type bound: int
        :rtype: List[int]
        """
        xs = [x ** i for i in range(int(math.log(bound) // math.log(x)) + 1)] if x > 1 else [1]
        ys = [y ** i for i in range(int(math.log(bound) // math.log(y)) + 1)] if y > 1 else [1]
        return list({x + y for x in xs for y in ys if x + y <= bound})
