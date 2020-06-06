class Solution:

    def __init__(self, radius, x_center, y_center):
        """
        :type radius: float
        :type x_center: float
        :type y_center: float
        """
        self.radius = radius
        self.radius2 = radius ** 2
        self.xc = x_center
        self.xmin = x_center - radius
        self.xmax = x_center + radius
        self.yc = y_center
        self.ymin = y_center - radius
        self.ymax = y_center + radius
        

    def randPoint(self):
        """
        :rtype: List[float]
        """
        while True:
            x = random.uniform(self.xmin, self.xmax)
            y = random.uniform(self.ymin, self.ymax)
            if (x - self.xc) ** 2 + (y - self.yc) ** 2 <= self.radius2:
                return (x, y)
        


# Your Solution object will be instantiated and called as such:
# obj = Solution(radius, x_center, y_center)
# param_1 = obj.randPoint()
