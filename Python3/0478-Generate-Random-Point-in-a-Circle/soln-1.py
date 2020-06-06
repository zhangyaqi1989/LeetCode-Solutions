class Solution:

    def __init__(self, radius: float, x_center: float, y_center: float):
        self.radius = radius
        self.x_center = x_center
        self.y_center = y_center
        
    def randPoint(self) -> List[float]:
        theta = random.uniform(0, math.pi * 2)
        r = self.radius * math.sqrt(random.uniform(0, 1))
        return r * math.cos(theta) + self.x_center, r * math.sin(theta) + self.y_center
        


# Your Solution object will be instantiated and called as such:
# obj = Solution(radius, x_center, y_center)
# param_1 = obj.randPoint()
