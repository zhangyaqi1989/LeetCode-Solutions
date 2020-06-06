class Solution:
    def slidingPuzzle(self, board: List[List[int]]) -> int:
        moves = {0: {1, 3}, 1:{0, 2, 4}, 2:{1, 5}, 3:{0, 4}, 4:{1, 3, 5}, 5:{2, 4}}
        target = "123450"
        start = ''.join(str(val) for row in board for val in row)
        frontier = collections.deque([(start, start.index('0'))])
        seen = {start}
        step = 0
        while frontier:
            sz = len(frontier)
            for i in range(sz):
                node, i = frontier.popleft()
                if node == target:
                    return step
                for j in moves[i]:
                    new_node = list(node)
                    new_node[i], new_node[j] = new_node[j], new_node[i]
                    new_node = ''.join(new_node)
                    if new_node not in seen:
                        seen.add(new_node)
                        frontier.append((new_node, j))
            step += 1
        return -1
        
