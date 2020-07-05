class Solution:
    def minInteger(self, num: str, k: int) -> str:
        lst = list(map(int, num))
        # print(lst)
        n = len(lst)
        for i in range(n):
            mn = lst[i]
            mn_idx = i
            for j in range(i + 1, min(n, i + k + 1)):
                if lst[j] < mn:
                    mn = lst[j]
                    mn_idx = j
            if mn != lst[i]:
                lst[i + 1:mn_idx + 1] = lst[i:mn_idx]
                lst[i] = mn
                k -= mn_idx - i
                if not k:
                    break
        return ''.join(map(str, lst))
