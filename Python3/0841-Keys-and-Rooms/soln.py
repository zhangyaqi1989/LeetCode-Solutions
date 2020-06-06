class Solution(object):
    def canVisitAllRooms(self, rooms):
        """
        :type rooms: List[List[int]]
        :rtype: bool
        """
        n = len(rooms)
        visited = [1] + [0] * (n - 1)
        stack = [0]
        while stack:
            node = stack.pop()
            for nei in rooms[node]:
                if not visited[nei]:
                    visited[nei] = 1
                    stack.append(nei)
        return all(visited)