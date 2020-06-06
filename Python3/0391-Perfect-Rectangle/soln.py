class Solution:
    def isRectangleCover(self, rectangles: List[List[int]]) -> bool:
        if not any(rectangles):
            return False
        xmin = ymin = math.inf
        xmax = ymax = -math.inf
        seen = set()
        area = 0
        for x1, y1, x2, y2 in rectangles:
            xmin = min(xmin, x1)
            xmax = max(xmax, x2)
            ymin = min(ymin, y1)
            ymax = max(ymax, y2)
            
            area += (y2 - y1) * (x2 - x1)
            points = (x1, y1), (x1, y2), (x2, y2), (x2, y1)
            for p in points:
                if p in seen:
                    seen.remove(p)
                else:
                    seen.add(p)
        corners = (xmin, ymin), (xmin, ymax), (xmax, ymax), (xmax, ymin)
        for c in corners:
            if c not in seen:
                return False
        return area == (xmax - xmin) * (ymax - ymin) and len(seen) == 4
            
