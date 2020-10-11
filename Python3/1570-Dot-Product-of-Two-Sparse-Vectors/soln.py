class SparseVector:
    def __init__(self, nums: List[int]):
        self.non_zeros = {i : num for i, num in enumerate(nums)}

    # Return the dotProduct of two sparse vectors
    def dotProduct(self, vec: 'SparseVector') -> int:
        ans = 0
        for idx in (self.non_zeros.keys() & vec.non_zeros.keys()):
            ans += self.non_zeros[idx] * vec.non_zeros[idx]
        return ans

# Your SparseVector object will be instantiated and called as such:
# v1 = SparseVector(nums1)
# v2 = SparseVector(nums2)
# ans = v1.dotProduct(v2)
