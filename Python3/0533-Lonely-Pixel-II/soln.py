class Solution:
    def findBlackPixel(self, picture: List[List[str]], N: int) -> int:
        count = 0
        for col in zip(*picture):
            if col.count('B') != N:
                continue
            row = picture[col.index('B')]
            if row.count('B') != N:
                continue
            if picture.count(row) != N:
                continue
            count += 1
        return count * N
