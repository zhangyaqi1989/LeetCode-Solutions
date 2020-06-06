class Solution:
    def validUtf8(self, data):
        """
        :type data: List[int]
        :rtype: bool
        """
        count = 0
        for num in data:
            if not count:
                if (num >> 5) == 0b110:
                    count = 1
                elif (num >> 4) == 0b1110:
                    count = 2
                elif (num >> 3) == 0b11110:
                    count = 3
                elif (num >> 7):
                    return False
            else:
                if num >> 6 != 0b10:
                    return False
                count -= 1;
        return count == 0