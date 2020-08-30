class Solution:
    def containsPattern(self, arr: List[int], m: int, k: int) -> bool:
        n = len(arr)
        mk = m * k
        for i in range(n - mk + 1):
            if all(a == b for a, b in zip(itertools.islice(arr, i, i + mk), itertools.cycle(arr[i : i + m]))):
                return True
        return False
