class Solution:
    def canDistribute(self, nums: List[int], quantity: List[int]) -> bool:
        counter = collections.Counter(nums)
        quantity.sort(reverse=True)
        left = list(counter.values())
        def dfs(idx):
            if idx == len(quantity):
                return True
            need = quantity[idx]
            for i, val in enumerate(left):
                if val >= need:
                    left[i] -= need
                    if dfs(idx + 1):
                        return True
                    left[i] += need
        return dfs(0)
