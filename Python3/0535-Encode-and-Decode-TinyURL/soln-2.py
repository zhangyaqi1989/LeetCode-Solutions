class Codec:
    
    def __init__(self):
        self.d = {}
        self.size = 0
        

    def encode(self, longUrl):
        """Encodes a URL to a shortened URL.
        
        :type longUrl: str
        :rtype: str
        """
        self.d[self.size] = longUrl
        temp = self.size
        self.size += 1
        return "http://tinyurl.com/" + str(temp)
        

    def decode(self, shortUrl):
        """Decodes a shortened URL to its original URL.
        
        :type shortUrl: str
        :rtype: str
        """
        return self.d[int(shortUrl.split('/')[-1])]
        

# Your Codec object will be instantiated and called as such:
# codec = Codec()
# codec.decode(codec.encode(url))
