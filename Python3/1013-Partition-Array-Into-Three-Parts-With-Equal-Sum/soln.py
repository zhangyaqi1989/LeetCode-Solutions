class Solution:
    def canThreePartsEqualSum(self, A: List[int]) -> bool:
        total = sum(A)
        if total % 3 != 0:
            return False
        cur = cnt = 0
        avg = total // 3
        for num in A:
            cur += num
            if cur == avg:
                cnt += 1
                cur = 0
                if cnt == 3:
                    return True
        return False
