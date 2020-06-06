class Solution(object):
    def allCellsDistOrder(self, R, C, r0, c0):
        """
        :type R: int
        :type C: int
        :type r0: int
        :type c0: int
        :rtype: List[List[int]]
        """
        queue = collections.deque([(r0, c0)])
        seen = set()
        seen.add((r0, c0))
        ans = []
        while queue:
            i, j = queue.popleft()
            ans.append([i, j])
            for newi, newj in (i - 1, j), (i + 1, j), (i, j - 1), (i, j + 1):
                if 0 <= newi < R and 0 <= newj < C and (newi, newj) not in seen:
                    seen.add((newi, newj))
                    queue.append((newi, newj))
        return ans

