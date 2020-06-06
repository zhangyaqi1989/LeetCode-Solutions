class Solution(object):
    def countCornerRectangles(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        if not any(grid): return 0
        s = []
        ans = 0
        for i, row in enumerate(grid):
            s.append({j for j, val in enumerate(row) if val})
        for i in range(len(grid)):
            for j in range(i):
                match = len(s[i] & s[j])
                if match >= 2:
                    ans += match * (match - 1) // 2
        return ans