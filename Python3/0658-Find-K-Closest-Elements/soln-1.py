class Solution:
    def findClosestElements(self, arr, k, x):
        """
        :type arr: List[int]
        :type k: int
        :type x: int
        :rtype: List[int]
        """
        lefts, rights = [], []
        idx = bisect.bisect_left(arr, x)
        l, r = idx - 1, idx # this is important
        count = k
        while count:
            if l < 0:
                rights.extend(arr[r:r+count])
                break
            if r >= len(arr):
                lefts.extend(arr[l-count+1:l+1][::-1])
                break
            if x - arr[l] <= arr[r] - x:
                lefts.append(arr[l])
                l -= 1
            else:
                rights.append(arr[r])
                r += 1
            count -= 1
        return lefts[::-1] + rights