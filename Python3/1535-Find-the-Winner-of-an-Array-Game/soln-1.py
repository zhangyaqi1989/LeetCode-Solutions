class Solution:
    def getWinner(self, arr: List[int], k: int) -> int:
        cur = arr[0]
        win = 0
        for i in range(1, len(arr)):
            if arr[i] > cur:
                cur = arr[i]
                win = 0
            win += 1
            if win == k:
                return cur
        return max(arr)
