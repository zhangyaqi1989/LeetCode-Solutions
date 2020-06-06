class Solution:
    def canVisitAllRooms(self, rooms: List[List[int]]) -> bool:
        n = len(rooms)
        visited = [False] * n
        visited[0] = True
        stack = [0]
        cnt = 0
        while stack:
            room = stack.pop()
            cnt += 1
            for nei in rooms[room]:
                if not visited[nei]:
                    stack.append(nei)
                    visited[nei] = True
        return cnt == n
