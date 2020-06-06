class Solution:
    def findLonelyPixel(self, picture: List[List[str]]) -> int:
        m, n = len(picture), len(picture[0])
        rows, cols = [0] * m, [0] * n
        for i, row in enumerate(picture):
            for j, pixel in enumerate(row):
                if pixel == 'B':
                    rows[i] += 1
                    cols[j] += 1
        cnt = 0
        for i, row in enumerate(picture):
            for j, pixel in enumerate(row):
                if pixel == 'B' and rows[i] == 1 and cols[j] == 1:
                    cnt += 1
        return cnt
