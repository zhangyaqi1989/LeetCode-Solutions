class Solution:
    def minArea(self, image: List[List[str]], x: int, y: int) -> int:
        def first(lo, hi, valid):
            while lo < hi:
                mid = (lo + hi) >> 1
                if valid(mid):
                    hi = mid
                else:
                    lo = mid + 1
            return lo
        m, n = len(image), len(image[0])
        top = first(0, x, lambda x : any(val == '1' for val in image[x]))
        bottom = first(x, m, lambda x : all(val == '0' for val in image[x]))
        left = first(0, y, lambda y : any(row[y] == '1' for row in image))
        right = first(y, n, lambda y : all(row[y] == '0' for row in image))
        # print(top, bottom, left, right)
        return (bottom - top) * (right - left)
