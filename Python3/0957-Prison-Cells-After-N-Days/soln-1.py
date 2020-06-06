class Solution:
    def prisonAfterNDays(self, cells: List[int], N: int) -> List[int]:
        # use integer to represent cells
        def encode(lst):
            ans = 0
            for i, num in enumerate(lst):
                if num == 1:
                    ans |= (1 << i)
            return ans
        def decode(num):
            lst = [None] * 8
            for i in range(8):
                lst[i] = 1 if (num & (1 << i)) != 0 else 0
            return lst
        def update(num):
            ans = 0
            for i in range(1, 7):
                a = num & (1 << (i - 1))
                b = num & (1 << (i + 1))
                if (a == 0 and b == 0) or (a != 0 and b != 0):
                    ans |= (1 << i)
            return ans
        num = encode(cells)
        records = {num : 0}
        for i in range(1, N + 1):
            num = update(num)
            if num in records:
                pre = records[num]
                period = i - pre
                left = N - i
                for j in range(left % period):
                    num = update(num)
                break
            else:
                records[num] = i
        return decode(num)
