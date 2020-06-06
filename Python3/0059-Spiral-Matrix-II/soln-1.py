class Solution:
    def generateMatrix(self, n: int) -> List[List[int]]:
        end = n * n
        d = 1 + 0j
        pos = 0 + 0j
        num = 1
        ans = [[0] * n for _ in range(n)]
        while num <= end:
            ans[int(pos.imag)][int(pos.real)] = num
            new_pos = pos + d
            if new_pos.real < 0 or new_pos.real >= n or new_pos.imag < 0 or new_pos.imag >= n or ans[int(new_pos.imag)][int(new_pos.real)] != 0:
                d *= 1j
            pos = pos + d
            num += 1
        return ans
