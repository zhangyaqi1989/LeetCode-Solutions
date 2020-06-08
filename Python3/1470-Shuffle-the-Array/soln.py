from functools import reduce
class Solution:
    def shuffle(self, nums: List[int], n: int) -> List[int]:
        return reduce(operator.add, ([nums[i], nums[i + n]] for i in range(n)), [])
