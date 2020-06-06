from functools import lru_cache
class Solution:
    def minHeightShelves(self, books: List[List[int]], shelf_width: int) -> int:
        @lru_cache(None)
        def helper(lo, hi):
            if hi <= lo:
                return 0
            if sum(books[idx][0] for idx in range(lo, hi)) <= shelf_width:
                return max(books[idx][1] for idx in range(lo, hi))
            cnt = books[lo][0]
            height = books[lo][1]
            lo += 1
            while lo < hi and cnt + books[lo][0] <= shelf_width and height >= books[lo][1]:
                cnt += books[lo][0]
                lo += 1
            ans = helper(lo, hi) + height
            while lo < hi and cnt <= shelf_width:
                height = max(height, books[lo][1])
                cnt += books[lo][0]
                lo += 1
                if cnt <= shelf_width:
                    ans = min(ans, helper(lo, hi) + height)
            return ans
        return helper(0, len(books))
            
        
