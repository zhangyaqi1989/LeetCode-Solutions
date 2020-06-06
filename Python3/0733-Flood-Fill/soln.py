class Solution:
    def floodFill(self, image, sr, sc, newColor):
        """
        :type image: List[List[int]]
        :type sr: int
        :type sc: int
        :type newColor: int
        :rtype: List[List[int]]
        """
        color = image[sr][sc]
        m, n  = len(image), len(image[0])
        stack = [(sr, sc)]
        seen  = {(sr, sc)}
        image[sr][sc] = newColor
        while stack:
            i, j = stack.pop()
            for newi, newj in (i - 1, j), (i + 1, j), (i, j - 1), (i, j + 1):
                if 0 <= newi < m and 0 <= newj < n and image[newi][newj] == color and (newi, newj) not in seen:
                    image[newi][newj] = newColor
                    seen.add((newi, newj))
                    stack.append((newi, newj))
        return image
