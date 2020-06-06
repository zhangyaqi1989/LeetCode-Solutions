import functools
class Solution:
    def outerTrees(self, points):
        """
        :type points: List[Point]
        :rtype: List[Point]
        """
        def orientation(p, q, r):
            "if pqr is ccw, return positive"
            return (q.x - p.x) * (r.y - q.y) - (q.y - p.y) * (r.x - q.x) 
        
        def monotone_chain(hull, point):
            "Implement monotone chain algorithm."
            hull.append(point)
            while len(hull) >= 3 and orientation(*hull[-3:]) < 0:
                hull.pop(-2)
            return hull
        
        points = sorted(points, key=operator.attrgetter('x', 'y'))
        lower = functools.reduce(monotone_chain, iter(points), [])
        upper = functools.reduce(monotone_chain, reversed(points), [])
        return list(set(lower + upper))
