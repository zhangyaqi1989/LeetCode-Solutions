class Solution:
    def slidingPuzzle(self, board):
        """
        :type board: List[List[int]]
        :rtype: int
        """
        # 0 1 2
        # 3 4 5
        moves = ((1, 3), (0, 2, 4), (1, 5), (0, 4), (1, 3, 5), (2, 4))
        cnt = 0
        init = [num for row in board for num in row]
        visited = {tuple(init)}
        queue = collections.deque([(init, init.index(0))])
        while queue:
            size = len(queue)
            for _ in range(size):
                state, idx = queue.popleft()
                if state == [1,2,3,4,5,0]:
                    return cnt
                for move in moves[idx]:
                    new_state = state[:]
                    new_state[idx], new_state[move] = new_state[move], new_state[idx]
                    if tuple(new_state) not in visited:
                        visited.add(tuple(new_state))
                        queue.append((new_state, move))
            cnt += 1
        return -1