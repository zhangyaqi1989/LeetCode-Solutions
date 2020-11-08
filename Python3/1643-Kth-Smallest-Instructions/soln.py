class Solution:
    def kthSmallestPath(self, destination: List[int], k: int) -> str:
        # HHHVV
        v, h = destination
        ans = ''
        for i in range(v + h):
            if k == 1:
                ans += 'H' * h + 'V' * v
                break
            else:
                number = math.comb(h - 1 + v, v)
                if k <= number:
                    ans += 'H'
                    h -= 1
                else:
                    k -= number
                    ans += 'V'
                    v -= 1
        return ans
