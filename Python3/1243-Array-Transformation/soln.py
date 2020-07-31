class Solution:
    def transformArray(self, arr: List[int]) -> List[int]:
        n = len(arr)
        while True:
            change = False
            new_arr = arr[:]
            for i in range(1, n - 1):
                if arr[i] < arr[i - 1] and arr[i] < arr[i + 1]:
                    new_arr[i] += 1
                    change = True
                if arr[i] > arr[i - 1] and arr[i] > arr[i + 1]:
                    new_arr[i] -= 1
                    change = True
            arr = new_arr
            if not change:
                break
        return arr
