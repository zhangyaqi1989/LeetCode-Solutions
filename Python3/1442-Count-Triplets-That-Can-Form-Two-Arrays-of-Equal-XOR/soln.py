class Solution:
    def countTriplets(self, arr: List[int]) -> int:
        pres = [0]
        for num in arr:
            pres.append(pres[-1] ^ num)
            # 0 <= i < j <= k < arr.length
        n = len(arr)
        cnt = 0
        for i in range(n):
            for j in range(i + 1, n):
                for k in range(j, n):
                    a = pres[j] ^ pres[i]
                    b = pres[k + 1] ^ pres[j]
                    if a == b:
                        cnt += 1
        return cnt
