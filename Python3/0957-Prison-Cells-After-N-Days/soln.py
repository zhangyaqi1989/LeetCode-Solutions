class Solution:
    def prisonAfterNDays(self, cells, N):
        """
        :type cells: List[int]
        :type N: int
        :rtype: List[int]
        """
        def update(cells):
            "Update cells once according to the rule."
            ans = [0] * len(cells)
            for i in range(1, len(cells) - 1):
                if cells[i - 1] == cells[i + 1]:
                    ans[i] = 1
            return tuple(ans)
        seen = {tuple(cells) : 0}
        for i in range(1, N + 1):
            cells = update(cells)
            if cells in seen:
                period = i - seen[cells]
                break
            seen[cells] = i
        else:
            return cells
        left = (N - i) % period
        for i in range(left):
            cells = update(cells)
        return list(cells)
