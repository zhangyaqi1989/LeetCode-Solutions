class MajorityChecker:

    def __init__(self, arr: List[int]):
        self.nums = arr
        self.idxes = collections.defaultdict(list)
        for i, num in enumerate(arr):
            self.idxes[num].append(i)


    def query(self, left: int, right: int, threshold: int) -> int:
        for _ in range(20):
            idx = random.randint(left, right)
            pick = self.nums[idx]
            l = bisect.bisect_left(self.idxes[pick], left)
            r = bisect.bisect_right(self.idxes[pick], right)
            if r - l >= threshold:
                return pick
        return -1


# Your MajorityChecker object will be instantiated and called as such:
# obj = MajorityChecker(arr)
# param_1 = obj.query(left,right,threshold)
