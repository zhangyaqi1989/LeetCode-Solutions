class Solution:
    def largestMultipleOfThree(self, digits: List[int]) -> str:
        m1 = [1, 4, 7, 2, 5, 8]
        m2 = [2, 5, 8, 1, 4, 7]
        counter = [0] * 10
        total = 0
        for d in digits:
            counter[d] += 1
            total += d
        while total % 3 != 0:
            m = m1 if total % 3 == 1 else m2
            for d in m:
                if counter[d] > 0:
                    counter[d] -= 1
                    total -= d
                    break
        ans = []
        for d in range(9, -1, -1):
            ans.extend([d] * counter[d])
        if not ans:
            return ""
        return '0' if ans[0] == 0 else ''.join(map(str, ans))
