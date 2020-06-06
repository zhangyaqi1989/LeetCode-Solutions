class Solution:
    def isAdditiveNumber(self, num):
        """
        :type num: str
        :rtype: bool
        """
        n = len(num)
        for i in range(n - 2):
            first = int(num[:i + 1])
            if str(first) != num[:i + 1]:
                break
            for j in range(i + 2, n):
                first = int(num[:i + 1])
                second = int(num[i + 1:j])
                if str(second) != num[i + 1:j]:
                    break
                idx = j
                while idx < n:
                    nxt = first + second
                    s = str(nxt)
                    if num[idx:idx + len(s)] != s:
                        break
                    idx = idx + len(s)
                    first, second = second, nxt
                else:
                    return True
        return False