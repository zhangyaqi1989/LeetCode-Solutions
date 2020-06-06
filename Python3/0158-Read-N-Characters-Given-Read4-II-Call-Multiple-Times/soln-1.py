"""
The read4 API is already defined for you.

    @param buf, a list of characters
    @return an integer
    def read4(buf):

# Below is an example of how the read4 API can be called.
file = File("abcdefghijk") # File is "abcdefghijk", initially file pointer (fp) points to 'a'
buf = [' '] * 4 # Create buffer with enough space to store characters
read4(buf) # read4 returns 4. Now buf = ['a','b','c','d'], fp points to 'e'
read4(buf) # read4 returns 4. Now buf = ['e','f','g','h'], fp points to 'i'
read4(buf) # read4 returns 3. Now buf = ['i','j','k',...], fp points to end of file
"""
class Solution:
    def __init__(self):
        self.bufsize = 0
        self.readptr = 0
        self.temp = [''] * 4

    def read(self, buf, n):
        """
        :type buf: Destination buffer (List[str])
        :type n: Number of characters to read (int)
        :rtype: The number of actual characters read (int)
        """
        cnt = 0
        while n > 0:
            if self.readptr == self.bufsize:
                k = read4(self.temp)
                self.readptr = 0
                self.bufsize = k
                if k == 0:
                    break
            num = min(self.bufsize - self.readptr, n)
            for i in range(num):
                buf[cnt] = self.temp[self.readptr]
                self.readptr += 1
                cnt += 1
            n -= num
        return cnt
        
