class Solution:
    def lemonadeChange(self, bills):
        """
        :type bills: List[int]
        :rtype: bool
        """
        # pay 5/10/20 bill
        fives, tens = 0, 0
        for bill in bills:
            if bill == 5:
                fives += 1
            elif bill == 10:
                if not fives:
                    return False
                else:
                    fives -= 1
                tens += 1
            else:
                left = 15
                if tens:
                    tens -= 1
                    left = 5
                if fives * 5 >= left:
                    fives -= left // 5
                else:
                    return False
        return True