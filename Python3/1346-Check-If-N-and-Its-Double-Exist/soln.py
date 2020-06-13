class Solution:
    def checkIfExist(self, arr: List[int]) -> bool:
        counter = collections.Counter(arr)
        for key, cnt in counter.items():
            if (key == 0 and cnt > 1) or (key != 0 and 2 * key in counter):
                return True
        return False
