class Solution(object):
    def findLonelyPixel(self, picture):
        """
        :type picture: List[List[str]]
        :rtype: int
        """
        counter = collections.defaultdict(int)
        for i, row in enumerate(picture):
            for j, val in enumerate(row):
                if val == 'B':
                    counter[0, i] += 1
                    counter[1, j] += 1
        cnt = 0
        for i in range(len(picture)):
            for j in range(len(picture[0])):
                if picture[i][j] == 'B' and counter[0, i] == counter[1, j] == 1:
                    cnt += 1
        return cnt