class Solution:
    def findLucky(self, arr: List[int]) -> int:
        N = 501
        counter = [0] * N
        for num in arr:
            counter[num] += 1
        for idx in range(N - 1, 0, -1):
            if counter[idx] == idx:
                return idx
        return -1
