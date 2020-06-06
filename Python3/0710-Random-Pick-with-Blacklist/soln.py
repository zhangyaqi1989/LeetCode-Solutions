class Solution:

    def __init__(self, N: int, blacklist: List[int]):
        # 0 1 2 3 4 5, [2, 4]
        self.N = N
        # self.blacklist = sorted(blacklist)
        self.M = N - len(blacklist)
        blacklist.sort()
        blackset = set(blacklist)
        j = self.N - 1
        self.black_map = {}
        for num in blacklist:
            while j >= self.M:
                if j not in blackset:
                    self.black_map[num] = j
                    j -= 1
                    break
                j -= 1
            else:
                break
        # print(self.black_map)
        
        

    def pick(self) -> int:
        # 0 1 5 3
        idx = random.randint(0, self.M - 1)
        if idx in self.black_map:
            return self.black_map[idx]
        else:
            return idx


# Your Solution object will be instantiated and called as such:
# obj = Solution(N, blacklist)
# param_1 = obj.pick()
