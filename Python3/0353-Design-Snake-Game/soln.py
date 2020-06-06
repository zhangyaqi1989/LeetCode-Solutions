class SnakeGame:

    def __init__(self, width, height, food):
        """
        Initialize your data structure here.
        @param width - screen width
        @param height - screen height 
        @param food - A list of food positions
        E.g food = [[1,1], [1,0]] means the first food is positioned at [1,1], the second is at [1,0].
        :type width: int
        :type height: int
        :type food: List[List[int]]
        """
        self.width = width
        self.height = height
        self.snake = collections.deque([(0, 0)])
        self.body = {(0, 0)}
        self.dir = {'U' : (-1, 0), 'D' : (1, 0), 'L' : (0, -1), 'R' : (0, 1)}
        self.food = food[::-1]
        self.score = 0

    def move(self, direction):
        """
        Moves the snake.
        @param direction - 'U' = Up, 'L' = Left, 'R' = Right, 'D' = Down 
        @return The game's score after the move. Return -1 if game over. 
        Game over when snake crosses the screen boundary or bites its body.
        :type direction: str
        :rtype: int
        """
        i, j = self.snake[-1]
        di, dj = self.dir[direction]
        new_head = i + di, j + dj
        if 0 <= i + di < self.height and 0 <= j + dj < self.width and (new_head == self.snake[0] or new_head not in self.body):
            if self.food and new_head == tuple(self.food[-1]):
                self.food.pop()
                self.score += 1
            else:
                # print(self.snake)
                self.body.remove(self.snake.popleft())
            self.body.add(new_head)
            self.snake.append(new_head)
            return self.score
        else:
            return -1
# Your SnakeGame object will be instantiated and called as such:
# obj = SnakeGame(width, height, food)
# param_1 = obj.move(direction)