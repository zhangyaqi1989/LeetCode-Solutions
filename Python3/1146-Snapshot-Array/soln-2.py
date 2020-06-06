class SnapshotArray:

    def __init__(self, length: int):
        self.nums = [[(-1, 0)] for _ in range(length)]
        self.ops = {}
        self.cnt = 0

    def set(self, index: int, val: int) -> None:
        self.ops[index] = val

    def snap(self) -> int:
        ans = self.cnt
        self.cnt += 1
        for idx, val in self.ops.items():
            self.nums[idx].append((ans, val))
        self.ops.clear()
        return ans
        
    def get(self, index: int, snap_id: int) -> int:
        i = bisect.bisect_left(self.nums[index], (snap_id + 1, -1))
        return self.nums[index][i - 1][-1]


# Your SnapshotArray object will be instantiated and called as such:
# obj = SnapshotArray(length)
# obj.set(index,val)
# param_2 = obj.snap()
# param_3 = obj.get(index,snap_id)
