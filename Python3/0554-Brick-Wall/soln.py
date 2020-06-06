class Solution:
    def leastBricks(self, wall):
        """
        :type wall: List[List[int]]
        :rtype: int
        """
        counts = collections.Counter()
        for lst in wall:
            acc = 0
            for i in range(len(lst) - 1):
                acc += lst[i]
                counts[acc] += 1
        if not counts:
            return len(wall)
        return len(wall) - counts.most_common(1)[0][1]
