class Solution:
    def countSteppingNumbers(self, low: int, high: int) -> List[int]:
        frontier = deque(range(1, 10))
        ans = []
        if low == 0:
            ans.append(0)
        while frontier:
            num = frontier.popleft()
            if low <= num <= high:
                ans.append(num)
            if num < high:
                d = num % 10
                if d > 0:
                    frontier.append(num * 10 + d - 1)
                if d < 9:
                    frontier.append(num * 10 + d + 1)
        return ans
