"""
   This is the custom function interface.
   You should not implement it, or speculate about its implementation
   class CustomFunction:
       # Returns f(x, y) for any given positive integers x and y.
       # Note that f(x, y) is increasing with respect to both x and y.
       # i.e. f(x, y) < f(x + 1, y), f(x, y) < f(x, y + 1)
       def f(self, x, y):
  
"""

class Solution:
    def findSolution(self, customfunction: 'CustomFunction', z: int) -> List[List[int]]:
        ans = []
        f = customfunction.f
        hi = 1001
        for x in range(1, 1001):
            lo = 1
            while lo <= hi:
                mid = (lo + hi) >> 1
                val = f(x, mid)
                if val == z:
                    ans.append([x, mid])
                    break
                elif val < z:
                    lo = mid + 1
                else:
                    hi = mid - 1
        return ans
