class OrderedStream:

    def __init__(self, n: int):
        self._n = n
        self._ptr = 1
        self._nums = [None] * (n + 1)
        

    def insert(self, pair_id: int, value: str) -> List[str]:
        self._nums[pair_id] = value
        ans = []
        while self._ptr < len(self._nums) and self._nums[self._ptr] is not None:
            ans.append(self._nums[self._ptr])
            self._ptr += 1
        return ans


# Your OrderedStream object will be instantiated and called as such:
# obj = OrderedStream(n)
# param_1 = obj.insert(id,value)
