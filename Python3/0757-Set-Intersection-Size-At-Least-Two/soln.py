class Solution:
    def intersectionSizeTwo(self, intervals):
        """
        :type intervals: List[List[int]]
        :rtype: int
        """
        picks = []
        intervals = sorted(intervals, key=lambda x : x[1])
        for start, end in intervals:
            if len(picks) == 0 or picks[-1] < start:
                picks.extend([end - 1, end])
            elif picks[-2] < start:
                if picks[-1] == end:
                    picks.append(end - 1)
                else:
                    picks.append(end)
        return len(picks)
