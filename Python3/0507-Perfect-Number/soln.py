class Solution:
    def checkPerfectNumber(self, num):
        """
        :type num: int
        :rtype: bool
        """
        if num <= 0:
            return False
        extra = int(math.sqrt(num)) if int(math.sqrt(num)) ** 2 == num else 0
        return (sum(i + num // i for i in range(1, int(math.sqrt(num)) + 1) 
                    if num % i == 0) == 2 * num + extra)
