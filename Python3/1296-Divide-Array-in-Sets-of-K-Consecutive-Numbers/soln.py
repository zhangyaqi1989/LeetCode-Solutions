class Solution:
    def isPossibleDivide(self, nums: List[int], k: int) -> bool:
        n = len(nums)
        if n % k:
            return False
        left = list(collections.Counter(nums).items())
        heapq.heapify(left)
        for _ in range(n // k):
            temp = []
            try:
                cur = left[0][0] - 1
                for _ in range(k):
                    num, cnt = heapq.heappop(left)
                    if cur + 1 != num:
                        return False
                    cur = num
                    if cnt > 1:
                        temp.append((num, cnt - 1))
                for pair in temp:
                    heapq.heappush(left, pair)
            except:
                return False
        return True
