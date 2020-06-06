class Solution:
    def fairCandySwap(self, A: List[int], B: List[int]) -> List[int]:
        sa, sb = sum(A), sum(B)
        diff = (sb - sa) // 2
        B_set = set(B)
        for num in A:
            if num + diff in B_set:
                return [num, num + diff]
