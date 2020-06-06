class SnakeGame:

    def __init__(self, width: int, height: int, food: List[List[int]]):
        """
        Initialize your data structure here.
        @param width - screen width
        @param height - screen height 
        @param food - A list of food positions
        E.g food = [[1,1], [1,0]] means the first food is positioned at [1,1], the second is at [1,0].
        """
        # init: (0, 0)
        # length = 1
        self.body = {(0, 0)}
        self.food = food[::-1]
        self.snake = collections.deque([(0, 0)])
        self.score = 0
        self.dirs = dict(zip('ULRD', ((-1, 0), (0, -1), (0, 1), (1, 0))))
        self.C = width
        self.R = height
        

    def move(self, direction: str) -> int:
        """
        Moves the snake.
        @param direction - 'U' = Up, 'L' = Left, 'R' = Right, 'D' = Down 
        @return The game's score after the move. Return -1 if game over. 
        Game over when snake crosses the screen boundary or bites its body.
        """
        dr, dc = self.dirs[direction]
        r, c = self.snake[-1]
        nr, nc = r + dr, c + dc
        if nr < 0 or nr >= self.R or nc < 0 or nc >= self.C:
            return -1
        if self.food and self.food[-1][0] == nr and self.food[-1][1] == nc:
            self.food.pop()
            self.body.add((nr, nc))
            self.snake.append((nr, nc))
            self.score += 1
            return self.score
        else:
            self.body.remove(self.snake.popleft())
            if (nr, nc) in self.body:
                return -1
            self.body.add((nr, nc))
            self.snake.append((nr, nc))
            return self.score
        
        
# Your SnakeGame object will be instantiated and called as such:
# obj = SnakeGame(width, height, food)
# param_1 = obj.move(direction)
