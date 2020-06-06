# The read4 API is already defined for you.
# @param buf, a list of characters
# @return an integer
# def read4(buf):

class Solution(object):
    
    def __init__(self):
        self.queue = collections.deque()
        

    def read(self, buf, n):
        """
        :type buf: Destination buffer (List[str])
        :type n: Maximum number of characters to read (int)
        :rtype: The number of characters read (int)
        """
        buf4 = [""] * 4
        i = 0
        while True:
            l = read4(buf4)
            self.queue.extend(buf4[:l])
            need = min(len(self.queue), n - i)
            for j in range(need):
                buf[i] = self.queue.popleft()
                i += 1
            if not need:
                break
        return i