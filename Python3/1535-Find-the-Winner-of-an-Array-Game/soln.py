class Solution:
    def getWinner(self, arr: List[int], k: int) -> int:
        if k >= len(arr):
            return max(arr)
        dq = collections.deque(arr)
        cnt = 0
        ans = -1
        while True:
            a, b = dq.popleft(), dq.popleft()
            if a < b:
                a, b = b, a
            dq.appendleft(a)
            dq.append(b)
            if ans == a:
                cnt += 1
            else:
                ans = a
                cnt = 1
            if cnt >= k:
                return ans
        return -1
