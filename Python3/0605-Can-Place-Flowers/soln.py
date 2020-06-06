class Solution:
    def canPlaceFlowers(self, flowerbed, n):
        """
        :type flowerbed: List[int]
        :type n: int
        :rtype: bool
        """
        flowerbed = [0] + flowerbed + [0]
        for num, group in itertools.groupby(flowerbed):
            if num == 0:
                cnt = len(list(group))
                n -= (cnt - 1) // 2
                if n <= 0:
                    return True
        return False
        