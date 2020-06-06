# The read4 API is already defined for you.
# @param buf, a list of characters
# @return an integer
# def read4(buf):

class Solution(object):
    def read(self, buf, n):
        """
        :type buf: Destination buffer (List[str])
        :type n: Maximum number of characters to read (int)
        :rtype: The number of characters read (int)
        """
        ans = []
        cnt = 0
        temp = [None] * 4
        while cnt < n:
            k = read4(temp)
            size = min(k, n - cnt)
            buf[cnt:cnt + size] = temp[:size]
            cnt += size
            if k < 4:
                break
        return cnt